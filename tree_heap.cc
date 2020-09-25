#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <limits.h>

struct Heap {
  int size;
  int curr;
  int ele[0];
};

typedef Heap MaxHeap;
typedef Heap MinHeap;

void swin(MaxHeap* h);
void sink(MaxHeap* h);
MaxHeap* resize(MaxHeap* h, int size);

MaxHeap* CreateHeap(int n)
{
  //0索引不使用
  MaxHeap* h = (MaxHeap*)malloc(sizeof(MaxHeap) + 4*(n+1)); 
  if (h) {
    h->size = n;
    h->curr = 0;
  }
  return h;
}

MaxHeap* Insert(MaxHeap* h, int value)
{
  if (h->curr >= h->size) {
    //扩容2倍
    h = resize(h, h->size*2);
  }
  h->curr++;
  h->ele[h->curr] = value;
  swin(h);
  return h;
}

MaxHeap* resize(MaxHeap* h, int size)
{
  h->size = size;
  size++;
  h = (MaxHeap*)realloc(h, sizeof(MaxHeap) + (4*size));   
  return h;
}

//上浮
void swin(MaxHeap* h)
{
  int N = h->curr; 
  int p = N/2;
  while (N > 1 && h->ele[p] < h->ele[N]) {
    std::swap(h->ele[p], h->ele[N]); 
    N = p;
    p = N/2;
  }
}

//下沉
void sink(MaxHeap* h)
{
  int N = h->curr; 
  int pos = 1;
  int l = 2*pos;
  while (l <= N) {
    int r = 2*pos + 1; 
    if (r <= N && h->ele[l] < h->ele[r]) {
      l = r;
    }
    if (h->ele[l] < h->ele[pos])break;
    std::swap(h->ele[l], h->ele[pos]);
    pos = l;
    l = 2 * pos;
  }
}

int Max(MaxHeap* h)
{
  return h->curr >= 1 ? h->ele[1] : INT_MIN;
}

bool DelMax(MaxHeap* h)
{
  int max = Max(h);
  if (INT_MIN == max) {
    return false;
  }
  std::swap(h->ele[h->curr], h->ele[1]);
  h->curr--;
  sink(h);
  return true;
}

void ReleaseHeap(MaxHeap* h)
{
  h->size = 0;
  free(h);
}

int main()
{
  MaxHeap* h = CreateHeap(10);
  for (int i=0; i <= 10000000; i++) {
    h = Insert(h, i);
  }
  for (int i=0; i <= 13; ++i) {
    printf("Max value: %d\n", Max(h));
    DelMax(h);
  }
  ReleaseHeap(h);
  return 0;
}




