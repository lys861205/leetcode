#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <limits.h>

struct Heap {
  int size;
  int curr;
  bool (*compare)(int, int);
  int ele[0];
};

typedef Heap MaxHeap;
typedef Heap MinHeap;

void swin(Heap* h);
void sink(Heap* h);
Heap* resize(Heap* h, int size);

bool greater(int x, int y)
{
  return x > y;
}

bool less(int x, int y)
{
  return x < y;
}

MaxHeap* CreateMaxHeap(int n)
{
  //0索引不使用
  MinHeap* h = (MinHeap*)malloc(sizeof(MinHeap) + 4*(n+1)); 
  if (h) {
    h->size = n;
    h->curr = 0;
    h->compare = less;
  }
  return h;
}

MinHeap* CreateMinHeap(int n)
{
  //0索引不使用
  MaxHeap* h = (MaxHeap*)malloc(sizeof(MaxHeap) + 4*(n+1)); 
  if (h) {
    h->size = n;
    h->curr = 0;
    h->compare = greater;
  }
  return h;
}

Heap* Insert(Heap* h, int value)
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

Heap* resize(Heap* h, int size)
{
  h->size = size;
  size++;
  h = (Heap*)realloc(h, sizeof(Heap) + (4*size));   
  return h;
}

//上浮
void swin(Heap* h)
{
  int N = h->curr; 
  int p = N/2;
  while ( N > 1 && h->compare(h->ele[p], h->ele[N]) ) {
    std::swap(h->ele[p], h->ele[N]); 
    N = p;
    p = N/2;
  }
}

//下沉
void sink(Heap* h)
{
  int N = h->curr; 
  int pos = 1;
  int l = 2*pos;
  while (l <= N) {
    int r = 2*pos + 1; 
    if ( r <= N && h->compare(h->ele[l], h->ele[r]) ) {
      l = r;
    }
    if (h->compare(h->ele[l], h->ele[pos]))break;
    std::swap(h->ele[l], h->ele[pos]);
    pos = l;
    l = 2 * pos;
  }
}

int top(Heap* h)
{
  return h->curr >= 1 ? h->ele[1] : INT_MIN;
}

bool pop(Heap* h)
{
  if (top(h) == INT_MIN) {
    return false;
  }
  std::swap(h->ele[h->curr], h->ele[1]);
  h->curr--;
  sink(h);
  return true;
}

void ReleaseHeap(Heap* h)
{
  h->size = 0;
  free(h);
}

int main()
{
  printf("test Max heap ... \n");
  MaxHeap* h = CreateMaxHeap(10);
  for (int i=0; i <= 100000; i++) {
    h = Insert(h, i);
  }
  for (int i=0; i <= 13; ++i) {
    printf("Max value: %d\n", top(h));
    pop(h);
  }
  ReleaseHeap(h);

  printf("test Min heap ... \n");
  h = CreateMinHeap(10);
  for (int i=0; i <= 10000; i++) {
    h = Insert(h, i);
  }
  for (int i=0; i <= 13; ++i) {
    printf("Min value: %d\n", top(h));
    pop(h);
  }
  ReleaseHeap(h);

  return 0;
}




