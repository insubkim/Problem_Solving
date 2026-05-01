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

	for i := 0; i < t; i++ {
		var size int
		fmt.Fscan(r, &size)

		var word string
		fmt.Fscan(r, &word)

		if size%2 == 1 {
			fmt.Fprintln(w, "NO")
			continue
		}

		var open int = 0
		var close int = 0
		for i := 0; i < len(word); i++ {
			if word[i] == '(' {
				open++
			} else {
				close++
			}
		}

		if open == close {
			fmt.Fprintln(w, "YES")

		} else {
			fmt.Fprintln(w, "NO")
		}
	}
}
