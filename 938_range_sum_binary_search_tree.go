package main

import (
  "fmt"
  bst "./common"
)

func rangeSum(root *bst.Tree, l, r int) int {
  if root == nil {
    return 0
  }
  if root.V > l && root.V < r {
    return root.V + rangeSum(root.R, l, r) + rangeSum(root.L, l, r)
  } else if root.V == l || root.V == r {
    return root.V
  } else if root.V < l {
    return rangeSum(root.L, l, r)
  } else {
    return rangeSum(root.R, l, r)
  }
}

func main() {
  var root *bst.Tree
  root = bst.Add(root, 10)
  bst.Add(root, 5)
  bst.Add(root, 8)
  bst.Add(root, 11)
  bst.Print(root)
  fmt.Printf("\n%d\n", rangeSum(root, 5, 11))
}
