package main

import (
	"bufio"
	"cmp"
	"fmt"
	"os"
	"slices"
)

func main() {
	r := bufio.NewReader(os.Stdin)
	w := bufio.NewWriter(os.Stdout)
	defer w.Flush()

	var t int
	fmt.Fscan(r, &t)

	for t > 0 {
		var n int
		fmt.Fscan(r, &n)

		var arr []int
		for i := 0; i < n; i++ {
			var v int
			fmt.Fscan(r, &v)
			arr = append(arr, v)
		}

		slices.SortFunc(arr, func(a, b int) int {
			return cmp.Compare(b, a)
		})

		// fmt.Fprint(w, "=>", arr)
		// mod 체크
		var succ bool = true
		for i := 0; i < n-2; i++ {
			if arr[i+2] != arr[i]%arr[i+1] {
				succ = false
				break
			}
		}
		if succ {
			fmt.Fprintf(w, "%v %v\n", arr[0], arr[1])
		} else {
			fmt.Fprintf(w, "-1\n")
		}
		t--
	}

}
