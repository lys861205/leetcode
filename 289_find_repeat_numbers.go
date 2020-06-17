package main

import "fmt"

func repeatNumber(nums []int) int {
  fast := 0
  slow := 0
  for {
    if fast != slow && nums[fast] == nums[slow] {
      return nums[fast]
    } else {
      fast += 2
      slow += 1
    }
    fast = fast%len(nums)
    slow = slow%len(nums)
    fmt.Printf("%d-%d\n", slow, fast)
  }
}

func main() {
  var a = []int{1,4,6,3,4,5,2,7}
  fmt.Println(repeatNumber(a))
	fmt.Println("vim-go")
}
