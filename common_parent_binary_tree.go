package main

import (
  "fmt"
  bst "./common"
)

func ancestor(root, p, q *bst.Tree) *bst.Tree {
  if root == nil {
    return nil
  }
  if root == p || root == q {
    return root
  }
  lt := ancestor(root.L, p, q)
  rt := ancestor(root.R, p, q)
  if lt != nil && rt != nil {
    return root
  }
  if lt != nil {
    return lt
  }
  if rt != nil {
    return rt
  }
  return nil
}

func main() {
  var root *bst.Tree
  root = bst.Add(root, 10)
  root = bst.Add(root, 11)
  root = bst.Add(root, 12)
  root = bst.Add(root, 8)
  root = bst.Add(root, 9)
  root = bst.Add(root, 6)
  bst.Print(ancestor(root, root.L.R, root.R.R))
  fmt.Println()
  bst.Print(ancestor(root, root.L.L, root.L.R))
  fmt.Println()
	fmt.Println("vim-go")
}
