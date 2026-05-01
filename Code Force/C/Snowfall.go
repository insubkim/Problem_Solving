package main

import (
	"bufio"
	"fmt"
	"os"
)

var sol1 [200001]rune
var sol1_size int
var sol2 [200001]rune
var sol2_size int
var sol3 [200001]rune
var sol3_size int

func main() {
	r := bufio.NewReader(os.Stdin)
	w := bufio.NewWriter(os.Stdout)
	defer w.Flush()

	var t int = 0
	fmt.Fscan(r, &t)

	for i := 0; i < t; i++ {
		var n int
		fmt.Fscan(r, &n)

		sol1_size = 0
		sol2_size = 0
		sol3_size = 0
		for j := 0; j < n; j++ {
			var k rune
			fmt.Fscan(r, &k)
			if k%6 == 0 {
				fmt.Fprintf(w, "%v ", k)
			} else if k%2 == 0 {
				sol1[sol1_size] = k
				sol1_size++
			} else if k%3 == 0 {
				sol2[sol2_size] = k
				sol2_size++
			} else {
				sol3[sol3_size] = k
				sol3_size++
			}
		}

		for j := 0; j < sol1_size; j++ {
			fmt.Fprintf(w, "%v ", sol1[j])
		}
		for j := 0; j < sol3_size; j++ {
			fmt.Fprintf(w, "%v ", sol3[j])
		}
		for j := 0; j < sol2_size; j++ {
			fmt.Fprintf(w, "%v ", sol2[j])
		}
		fmt.Fprintf(w, "\n")
	}
}
