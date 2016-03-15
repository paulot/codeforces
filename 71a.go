package main

import "fmt"

func main() {
	var n int
	fmt.Scan(&n)

	var strings [101]string

	for i := 0; i < n; i++ {
		fmt.Scan(&strings[i])
	}

	for i := 0; i < n; i++ {
		if len(strings[i]) > 10 {
			fmt.Printf("%c%v%c\n", strings[i][0], len(strings[i])-2, strings[i][len(strings[i])-1])
		} else {
			fmt.Println(strings[i])
		}
	}
}
