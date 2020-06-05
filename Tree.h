#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <iomanip>

using namespace std;

struct Tree {
  int value;
  Tree* left;
  Tree* right;
};

Tree* BSTCreate(int value) 
{
  Tree* root = (Tree*)malloc(sizeof(Tree));
  if (NULL != root) {
    root->value = value;
    root->left = NULL;
    root->right = NULL;
  }
  return root;
}

Tree* BSTAppend(Tree* & root, Tree* t) {
  if (root == NULL) {
    root = t;
  }
  else if (t && t->value < root->value) {
    BSTAppend(root->left, t);
  }
  else if (t && t->value > root->value) {
    BSTAppend(root->right, t);
  }
  return root;
}

Tree* BSTAdd(Tree* root, int value) {
  if (root == NULL) {
    return BSTCreate(value);
  }
  Tree* node = BSTCreate(value);
  return BSTAppend(root, node);
}

Tree* BSTFind(Tree* root, int value)
{
  if (NULL == root) {
    return NULL;
  }
  if (value < root->value) {
    return BSTFind(root->left, value);
  }
  if (value > root->value) {
    return BSTFind(root->right, value);
  }
  if (value == root->value) {
    return root;
  }
}

void Print(Tree* root, int s, char c) {
  if (NULL == root) {
    return ;
  }
  Print(root->right, s+3, '/');
  cout << setw(s) << c << root->value << endl;
  Print(root->left, s+3, '\\');
}

void Print(Tree* root) {
  if (NULL == root) {
    return ;
  }
  printf("%d ", root->value);
  Print(root->left);
  Print(root->right);
}

void BSTRelese(Tree* root) 
{
  BSTRelese(root->left); 
  BSTRelese(root->right);
  if (root) free(root);
}



