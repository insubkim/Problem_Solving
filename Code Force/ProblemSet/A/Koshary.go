package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	r := bufio.NewReader(os.Stdin)
	w := bufio.NewWriter(os.Stdout)
	defer w.Flush()

	var t int
	fmt.Fscan(r, &t)

	// fmt.Println("input :", t)

	for i := 0; i < t; i++ {
		var y, x int
		fmt.Fscan(r, &x)
		fmt.Fscan(r, &y)

		if x%2 == 1 &&
			y%2 == 1 {
			fmt.Fprintln(w, "NO")
		} else {
			fmt.Fprintln(w, "YES")
		}
	}
}
