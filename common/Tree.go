package common

import (
  "fmt"
)

type Tree struct {
  V int
  L, R *Tree
}


func Add(t *Tree, value int) *Tree {
  if t == nil {
    t = new(Tree)
    t.V = value
    return t
  }
  if value > t.V {
    t.R = Add(t.R, value)
  } else {
    t.L = Add(t.L, value)
  }
  return t
}

func getMin(t *Tree) *Tree {
  for  {
    if t != nil {
      t = t.L
    } else {
      break
    }
  }
  return t
}

func Delete(t *Tree, value int) *Tree {
  if t == nil {
    return nil
  }
  if t.V == value {
    if t.L == nil && t.R == nil {
      return nil
    } else if (t.L == nil) {
      return t.R
    } else if (t.R == nil) {
      return t.L
    } else {
      tm := getMin(t.R) 
      t.V = tm.V
      t.R = Delete(t.R, tm.V)
    }
  } else if t.V > value {
    t.L = Delete(t.L, value)
  } else {
    t.R = Delete(t.R, value)
  }
  return t
}

func Print(t *Tree) {
  if t == nil {
    return ;
  }
  fmt.Printf("%d ", t.V);
  Print(t.L);
  Print(t.R);
}

