package main

import "fmt"

func main() {
	var f int
	for {
		n, _ := fmt.Scanf("%d", &f)
		if n != 1 {
			break
		}
		c := int(5. * (f - 32.) / 9.)
		fmt.Printf("Celsius = %v\n", c)
	}
}
