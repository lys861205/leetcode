public class MaxPQ 
  Key extendes Comparable<Key> {
  
  private Key[] pq;
  private int N = 0;

  public MaxPQ(int cap) {
    pq = (Key[]) new Comparable<Key>[cap+1];
  }

  public Key Max() {
    return pq[1];
  }

  public void insert(Key e) {
    N++;
    pq[N] = e;
    swin(N);
  }

  public Key delMax() {
    Key max = pq[1];
    exch(pq[N], pq[1]);
    pq[N] = null;
    --N;
    sink(1);
    return max;
  }
  //上浮
  public void swin(int k) {
    int parent = k/2;
    while (k>1 && less(parent(k), k)) {
      exch(parent, k);
      k = parent(k);
    }
  }
  
  public void sink(int k) {
    while (left(k) <= N) {
      int older = left(k);
      if (right(k) <= N && less(older, right(k))) {
        older = right(k);
      }
      if (less(older, k)) break;
      exch(older, k);
      k = older;
      }
    }
  }

  private void exch(int i, int j) {
    swap(pq[i], pq[j]);
  }

  private bool less(int i, int j) {
    return pq[i] < pq[j];
  }
};
};
