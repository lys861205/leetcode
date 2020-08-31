#include <stdlib.h>

int** _2DMalloc(int row, int col)
{
  int header = row * sizeof(int*);
  int data   = row * col * sizeof(int);
  int** rowptr = (int**)malloc(header + data);
  if (NULL == rowptr) return NULL;

  int* buf = (int*)(rowptr + row);
  for (int i=0; i < row; ++i) {
    rowptr[i] = buf + i * col;
  }
  return rowptr;
}

void _2DFree(int** ptr)
{
  if (ptr) {
    free(ptr);
    ptr = nullptr;
  }
}
#include <stdio.h>
int main()
{
  int** ptr = _2DMalloc(4, 4); 
  for (int i=0; i < 4; ++i) {
    for (int j=0; j < 4; ++j) {
      ptr[i][j] = i+j;
    }
  }
  printf("%p\n", ptr);
  return 0;
}
