package main

import "fmt"

func main() {
	var a, b, c int
	fmt.Scan(&a, &b, &c)

	for i := 0; i <= 10000; i++ {
		if (c-i*b)%a == 0 && (c-i*b)/a >= 0 {
			fmt.Printf("Yes\n")
			return
		}
	}

	fmt.Printf("No\n")
}
