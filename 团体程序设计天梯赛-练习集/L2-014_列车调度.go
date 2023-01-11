package main

import "fmt"

// case 1,2,3 timeout
func main() {
	var n int
	fmt.Scanf("%d", &n)

	s := make([]int, 0)
	for i := 0; i < n; i++ {
		var t int
		fmt.Scan(&t)
		p := UpperBound(s, t)
		if p == len(s) {
			s = append(s, t)
		} else {
			s[p] = t
		}
	}
	fmt.Println(len(s))
}

func UpperBound(arr []int, target int) int {
	lo, hi := 0, len(arr)-1
	for lo <= hi {
		mid := lo + (hi-lo)/2
		if arr[mid] > target {
			hi = mid - 1
		} else {
			lo = mid + 1
		}
	}
	return lo
}
