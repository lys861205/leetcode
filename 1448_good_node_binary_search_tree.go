package main

import (
  "fmt"
  "math"
  bst"./common"
)

func GoodNode(root *bst.Tree) int {
  return dfs(root, math.MinInt32)
}

func dfs(root *bst.Tree, max_value int) int {
  var cnt = 0
  if root == nil {
    return 0
  }
  if root.V >= max_value {
    cnt++
  }
  cnt += dfs(root.L, int(math.Max(float64(root.V), float64(max_value))))
  cnt += dfs(root.R, int(math.Max(float64(root.V), float64(max_value))))
  return cnt
}

func main() {
  var root *bst.Tree 
  root = bst.Add(root, 3)
  root = bst.Add(root, 4)
  root = bst.Add(root, 5)
  root = bst.Add(root, 6)
  fmt.Println(GoodNode(root))
	fmt.Println("vim-go")
}
