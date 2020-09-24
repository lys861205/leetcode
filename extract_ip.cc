#include <fstream>  
#include <iostream>  
#include <ctime>  
#include <string.h>


using namespace std;  
#define N 32           //临时文件数  

#define ID(x)  (x>>27)                 //x对应的文件编号  
#define VALUE(x) (x&0x07ffffff)        //x在文件中保存的值  
#define MAKE_IP(x,y)  ((x<<27)|y)      //由文件编号和值得到IP地址.  

#define MEM_SIZE  128*1024*1024       //需分配内存的大小为 MEM_SIZE*sizeof(unsigned)     

const char* data_path="test/ip.dat";        //ip数据  

//产生n个随机IP地址  
void make_data(const int& n)
{
  ofstream out(data_path,ios::out|ios::binary);
  srand((unsigned)(time(NULL)));
  if (out)
  {
    for (int i=0; i<n; ++i)
    {
      unsigned val=unsigned(rand());
      val = (val<<24)|val;              //产生unsigned类型的随机数

      out.write((char *)&val,sizeof (unsigned));
    }
  }
}

//找到访问次数最大的ip地址
int main()
{
  make_data(100000000);       //产生测试用的IP数据
  fstream arr[N];

  for (int i=0; i<N; ++i)                 //创建N个临时文件
  {
    char tmp_path[128];     //临时文件路径
    sprintf(tmp_path,"test/tmp%d.dat",i);
    arr[i].open(tmp_path, ios::trunc|ios::in|ios::out|ios::binary);  //打开第i个文件

    if( !arr[i])
    {
      cout<<"open file"<<i<<"error"<<endl;
    }
  }

  ifstream infile(data_path,ios::in|ios::binary);   //读入测试用的IP数据
  unsigned data;

  while(infile.read((char*)(&data), sizeof(data)))
  {
    unsigned val=VALUE(data);
    int key=ID(data);
    arr[ID(data)].write((char*)(&val), sizeof(val));           //保存到临时文件件中
  }

  for(unsigned i=0; i<N; ++i)
  {
    arr[i].seekg(0);
  }
  unsigned max_ip = 0;    //出现次数最多的ip地址
  unsigned max_times = 0;     //最大只出现的次数

  //分配512M内存,用于统计每个数出现的次数
  unsigned *count = new unsigned[MEM_SIZE];

  for (unsigned i=0; i<N; ++i)
  {
    memset(count, 0, sizeof(unsigned)*MEM_SIZE);

    //统计每个临时文件件中不同数字出现的次数
    unsigned data;
    while(arr[i].read((char*)(&data), sizeof(unsigned)))
    {
      ++count[data];
    }

    //找出出现次数最多的IP地址
    for(unsigned j=0; j<MEM_SIZE; ++j)
    {
      if(max_times<count[j])
      {
        max_times = count[j];
        max_ip = MAKE_IP(i,j);        // 恢复成原ip地址.
      }
    }
  }
  delete[] count;
  unsigned char *result=(unsigned char *)(&max_ip);
  printf("出现次数最多的IP为:%d.%d.%d.%d,共出现%d次\n",
      result[0], result[1], result[2], result[3], max_times);
}
