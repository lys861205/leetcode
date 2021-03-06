#!/bin/python

from redis import *
import sys
import threading
import time

crc16tab = [
  0x0000,0x1021,0x2042,0x3063,0x4084,0x50a5,0x60c6,0x70e7,
  0x8108,0x9129,0xa14a,0xb16b,0xc18c,0xd1ad,0xe1ce,0xf1ef,
  0x1231,0x0210,0x3273,0x2252,0x52b5,0x4294,0x72f7,0x62d6,
  0x9339,0x8318,0xb37b,0xa35a,0xd3bd,0xc39c,0xf3ff,0xe3de,
  0x2462,0x3443,0x0420,0x1401,0x64e6,0x74c7,0x44a4,0x5485,
  0xa56a,0xb54b,0x8528,0x9509,0xe5ee,0xf5cf,0xc5ac,0xd58d,
  0x3653,0x2672,0x1611,0x0630,0x76d7,0x66f6,0x5695,0x46b4,
  0xb75b,0xa77a,0x9719,0x8738,0xf7df,0xe7fe,0xd79d,0xc7bc,
  0x48c4,0x58e5,0x6886,0x78a7,0x0840,0x1861,0x2802,0x3823,                                                                                                             
  0xc9cc,0xd9ed,0xe98e,0xf9af,0x8948,0x9969,0xa90a,0xb92b,
  0x5af5,0x4ad4,0x7ab7,0x6a96,0x1a71,0x0a50,0x3a33,0x2a12,
  0xdbfd,0xcbdc,0xfbbf,0xeb9e,0x9b79,0x8b58,0xbb3b,0xab1a,
  0x6ca6,0x7c87,0x4ce4,0x5cc5,0x2c22,0x3c03,0x0c60,0x1c41,
  0xedae,0xfd8f,0xcdec,0xddcd,0xad2a,0xbd0b,0x8d68,0x9d49,
  0x7e97,0x6eb6,0x5ed5,0x4ef4,0x3e13,0x2e32,0x1e51,0x0e70,
  0xff9f,0xefbe,0xdfdd,0xcffc,0xbf1b,0xaf3a,0x9f59,0x8f78,
  0x9188,0x81a9,0xb1ca,0xa1eb,0xd10c,0xc12d,0xf14e,0xe16f,
  0x1080,0x00a1,0x30c2,0x20e3,0x5004,0x4025,0x7046,0x6067,
  0x83b9,0x9398,0xa3fb,0xb3da,0xc33d,0xd31c,0xe37f,0xf35e,
  0x02b1,0x1290,0x22f3,0x32d2,0x4235,0x5214,0x6277,0x7256,
  0xb5ea,0xa5cb,0x95a8,0x8589,0xf56e,0xe54f,0xd52c,0xc50d,
  0x34e2,0x24c3,0x14a0,0x0481,0x7466,0x6447,0x5424,0x4405,
  0xa7db,0xb7fa,0x8799,0x97b8,0xe75f,0xf77e,0xc71d,0xd73c,
  0x26d3,0x36f2,0x0691,0x16b0,0x6657,0x7676,0x4615,0x5634,
  0xd94c,0xc96d,0xf90e,0xe92f,0x99c8,0x89e9,0xb98a,0xa9ab,
  0x5844,0x4865,0x7806,0x6827,0x18c0,0x08e1,0x3882,0x28a3,
  0xcb7d,0xdb5c,0xeb3f,0xfb1e,0x8bf9,0x9bd8,0xabbb,0xbb9a,
  0x4a75,0x5a54,0x6a37,0x7a16,0x0af1,0x1ad0,0x2ab3,0x3a92,
  0xfd2e,0xed0f,0xdd6c,0xcd4d,0xbdaa,0xad8b,0x9de8,0x8dc9,
  0x7c26,0x6c07,0x5c64,0x4c45,0x3ca2,0x2c83,0x1ce0,0x0cc1,
  0xef1f,0xff3e,0xcf5d,0xdf7c,0xaf9b,0xbfba,0x8fd9,0x9ff8,
  0x6e17,0x7e36,0x4e55,0x5e74,0x2e93,0x3eb2,0x0ed1,0x1ef0
]

def crc16(buf, l):
  crc = 0
  for i in range(l):
    crc = (crc<<8) ^ crc16tab[((crc>>8) ^ ord(buf[i]))&0x00FF]
    crc &= 0xFFFF
  return crc


class MovedError(ResponseError):
  def __init__(self, resp):
    print(resp)

class IntSet(object):
  slots = 16384
  def __init__(self):
    self.bitmap = []
    for i in range(IntSet.slots//8):
      self.bitmap.append(0)
  
  def set(self, number):
    self.bitmap[number >> 3] |= (1 << (number & 7))
  
  def clear(self, number):
    self.bitmap[number >> 3] &= ~(1 << (number & 7))

  def exist(self, number):
    return (self.bitmap[number >> 3] & (1 << (number & 7)) != 0)

  def equal(self, other):
    return cmp(self.bitmap, other.bitmap) == 0

class ClusterData(object):
  def __init__(self, key, data):

    self.intset = IntSet()
    self.connected = False
    self.node_id = data['node_id']
    self.flag = data['flags']

    self.__parse_host(key)
    self.__parse_slot(data['slots'])

  def __parse_slot(self, slots):
    try:
      if not self.master():
        return
      for slot in slots:
        if len(slot) < 2:
          continue
        lo = int(slot[0])
        hi = int(slot[1]) + 1
        for s in range(lo, hi):
          self.intset.set(s)
    except ValueError, e:
      print('===>', self.host, self.port, slots)
     
  def __parse_host(self, hoststr):
    hoststr = hoststr.split("@")[0]
    ip_port = hoststr.split(":")
    self.host = ip_port[0]
    self.port = int(ip_port[1])

  def NodeId(self):
    return self.node_id

  def Host(self):
    return self.host

  def Port(self):
    return self.port

  def is_connected(self):
    return self.connected 

  def set_context(self, ctx):
    self.connected = True
    self.context = ctx

  def master(self):
    if self.flag == 'master' or self.flag == 'myself,master':
      return True
    else:
      return False

  def Context(self):
    return self.context

  def has_slot(self, slot):
    return self.intset.exist(slot)

  def equal_slot_and_assign(self, other):
    if not self.intset.equal(other.intset):
      self.intset = other.intset

  def __str__(self):
    return "[%s %s:%d]" % (self.node_id, self.host, self.port)

class RedisPing(threading.Thread):
  def __init__(self, cluster, timeout):
    threading.Thread.__init__(self)
    self.cluster = cluster
    self.timeout = timeout

  def run(self):
    while True:
      time.sleep(self.timeout)
      self.cluster.cluster_nodes()

class RedisCluster(object):
  """
  Implementation of the Redis cluster.
  """
  def __init__(self, host="localhost", port=6379,
               db=0, max_connections=None):
     self.nodes = {}
     self.max_connections = max_connections
     self.host = host
     self.port = port
     self.cluster_nodes()

     thd = RedisPing(self, 0.5)
     thd.start()

  def cluster_nodes(self):
     c = StrictRedis(self.host, self.port)
     try:
      nodes = c.execute_command("CLUSTER NODES")
      for k in nodes:
        if nodes[k]['connected']:
          node = ClusterData(k, nodes[k]) 
          if not self.nodes.has_key(node.NodeId()) and node.master():
            self.nodes[node.NodeId()] = node
          elif self.nodes.has_key(node.NodeId()):
            cur_node = self.nodes[node.NodeId()]
            cur_node.equal_slot_and_assign(node)

      self.__connect_master_node()
     except ResponseError, e:
      print("<%s:%d> %s" % (self.host, self.port, str(e)))
      sys.exit()

  def __connect_master_node(self):
    for node in self.nodes.values():
      if not node.is_connected():
        ctx = StrictRedis(node.Host(), node.Port(), max_connections = self.max_connections)
        node.set_context(ctx)
    
  def __pick_redis(self, key):
    slot = crc16(key, len(key)) & (16384-1)
    for node in self.nodes.values():
      if node.has_slot(slot):
        return node.Context()
    return None
    
  def set(self, name, value):
    try:
      redis_cli = self.__pick_redis(name)
      return redis_cli.set(name, value)
    except ResponseError, e:
      print(e)
      return 0 

  def get(self, name):
    redis_cli = self.__pick_redis(name)
    return redis_cli.get(name)

  def hset(self, name, key, value):
    redis_cli = self.__pick_redis(name)
    return redis_cli.hset(name, key, value)

  def hget(self, name, key):
    redis_cli = self.__pick_redis(name)
    return redis_cli.hget(name, key)

  def hgetall(self, name):
    redis_cli = self.__pick_redis(name)
    return redis_cli.hallget(name)

  def expire(self, name, time):
    redis_cli = self.__pick_redis(name)
    return redis_cli.expire(name, time)

rc = RedisCluster(host="10.139.48.96", port=7000)

d = {'1':'XXXXXX', '2': 'YYYYYYY', '3': 'lua', '10':'Go', '11':'python'}
for k in d:
  rc.hset("id:cluster", k, d[k])

rc.expire('id:cluster', 20)

for k in d:
  print rc.hget("id:cluster", k)


print('helllo')
conn = StrictRedis(host="10.139.48.96", port=7001)
try:
  print(conn.execute_command("asking"))
  print(conn.set("test", 'ccc'))
except MovedError as e:
  print(e)




