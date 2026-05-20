package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	var r *bufio.Reader = bufio.NewReader(os.Stdin)
	var w *bufio.Writer = bufio.NewWriter(os.Stdout)
	defer w.Flush()

	var t int
	fmt.Fscan(r, &t)

	for t > 0 {
		var n, a, b int64
		fmt.Fscan(r, &n, &a, &b)

		if a*3 < b {
			fmt.Fprintf(w, "%d\n", n*a)
		} else {
			var cost int64
			cost = (n / 3) * b

			var remainder int64
			remainder = n % 3

			if remainder*a < b {
				cost += remainder * a
			} else {
				cost += b
			}

			fmt.Fprintf(w, "%d\n", cost)
		}
		t--
	}

}
