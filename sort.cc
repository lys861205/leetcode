#include <stdio.h>
#include <algorithm>

using namespace std;

void bubble_sort(int* a, int n)
{
  for (int i=0; i < n; ++i) {
    for (int j=0; j < n - i - 1; ++j) {
      if (a[j] > a[j+1]) {
        swap(a[j], a[j+1]);
      }
    }
  }
}

void insert_sort(int* a, int n)
{
  for (int i=1; i < n; ++i) {
    int value = a[i];
    int j = i-1;
    for (; j >= 0; --j) {
      if (value < a[j]) {
        a[j+1] = a[j];
      }
      else {
        break;
      }
    }
    a[j+1] = value;
  }
}

void select_sort(int* a, int n)
{
  for (int i=0; i < n; ++i) {
    int ii = i;
    int min = a[i];
    int jj = i;
    for (int j=i; j < n; ++j) {
      if (a[j] < min) {
        min = a[j];
        jj = j;
      }
    }
    swap(a[ii], a[jj]);
  }
}

void quick_sort(int* a, int l, int r) 
{
  int lo = l;
  int hi = r;
  if (lo >= hi) return;
  if (lo < hi) {
    int pivot = a[lo];
    while (lo < hi) {
      while (lo < hi && a[hi] >= pivot)--hi;
      a[lo] = a[hi];
      while (lo < hi && a[lo] <= pivot)++lo;
      a[hi] = a[lo];
    }
    a[lo] = pivot;
    quick_sort(a, l, lo-1);
    quick_sort(a, lo+1, r);
  }
}

void print(int* a, int n)
{
  for (int i=0; i < n; ++i) {
    printf("%d ", a[i]);
  }
  printf("\n");
}

int main(int argc, char* argv[])
{
  int a[] = {3, 6, 2, 9, 1, 8, 7, 5};
  //bubble_sort(a, 8);
  //insert_sort(a, 8);
  //select_sort(a, 8);
  quick_sort(a, 0, 8);
  print(a, 8);
  
  return 0;
}
