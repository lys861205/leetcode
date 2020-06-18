package main

import "fmt"

func repeatNumber(nums []int) int {
  fast := 0
  slow := 0
  slow = nums[slow]
  fast = nums[nums[fast]]
  for {
    if slow != fast {
      slow = nums[slow]
      fast = nums[nums[fast]]
    } else {
      break
    }
  }
  pre1 := 0
  pre2 := slow
  for {
    if pre1 != pre2 {
      pre1 = nums[pre1]
      pre2 = nums[pre2]
    } else {
      break
    }
  }
  return pre1
}

func main() {
  var a = []int{1,4,6,3,4,5,2,7}
  fmt.Println(repeatNumber(a))
	fmt.Println("vim-go")
}
