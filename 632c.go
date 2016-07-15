package main

import (
	"fmt"
	"sort"
	"strings"
)

type ByLex []string

func (obj ByLex) Len() int {
	return len(obj)
}

func (obj ByLex) Swap(i, j int) {
	obj[i], obj[j] = obj[j], obj[i]
}

func lexLess(small, large string) bool {
	for i := 0; i < len(large); i++ {
		if small[i%len(small)] < large[i] {
			return true
		}
		if small[i%len(small)] > large[i] {
			return false
		}
	}
	// They are equivalent
	return true
}

func (obj ByLex) Less(i, j int) bool {
	if len(obj[i]) > len(obj[j]) {
		return !lexLess(obj[j], obj[i])
	} else {
		return lexLess(obj[i], obj[j])
	}
}

func main() {
	var n int
	fmt.Scan(&n)
	arr := make([]string, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&arr[i])
	}

	sort.Sort(ByLex(arr))
	fmt.Printf("%v\n", strings.Join(arr, ""))
}
