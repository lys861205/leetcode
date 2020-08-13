#include <stdio.h>
#include <vector>
#include <stdlib.h>

using namespace std;

struct Graph {
  int value;
  vector<Graph*> childs;
  Graph(int v):value(v){}
};

Graph* Add(Graph* root, int value)
{
  if (!root) {
    root = (Graph*)malloc(sizeof(Graph));
    root->value = value;
    return root;
  }
  Graph* child = (Graph*)malloc(sizeof(Graph));
  child->value = value;
  root->childs.push_back(child);
  return child;
}

void QueryPaths(Graph* root, vector<int>& paths)
{
  if (!root) return;
  paths.push_back(root->value);
  bool has_child = true;
  if (root->childs.size() <= 0) {
    has_child = false;
  }
  for (int i=0; i < root->childs.size(); ++i) {
    QueryPaths(root->childs[i], paths); 
  }
  if (!has_child) {
    for (int i=0; i < paths.size(); ++i) {
      printf("%d ", paths[i]);
    }
    printf("\n");
  }
  paths.pop_back();
}

int main()
{
  Graph root(1);
  Graph* temp = &root;
  for (int i=2; i < 10; ++i) {
    temp = Add(temp, i);
  }
  Graph* g1 = temp;
  for (int i=11; i < 15; ++i) {
    temp = Add(temp, i);
  }
  Graph* g2 = g1;
  for (int i=20; i > 13; --i) {
    g1 = Add(g1, i);
  }
  Graph* g3 = g2;
  for (int i=17; i > 13; --i) {
    g2 = Add(g2, i);
  }
  for (int i=20; i > 13; i =-2) {
    g3 = Add(g3, i);
  }
  vector<int> paths;
  QueryPaths(&root, paths);
  return 0;
}
