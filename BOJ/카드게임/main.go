package main

import "bufio"
import "fmt"
import "os"

func main() {
	r := bufio.NewReader(os.Stdin)
	w := bufio.NewWriter(os.Stdout)

	defer w.Flush()

	var A []int
	var B []int

	for i :=0; i < 10; i++ {
		var n int
		fmt.Fscan(r, &n)
		A = append(A, n)
	}

	for i :=0; i < 10; i++ {
		var n int
		fmt.Fscan(r, &n)
		B = append(B, n)
	}

	var winA int
	for i :=0; i < 10; i++ {
		if A[i] > B[i] {
			winA++
		} else if A[i] < B[i]{
			winA--
		}
	}
	
	if winA > 0 {
		fmt.Fprintln(w, "A")
	} else if winA < 0 {
		fmt.Fprintln(w, "B")
	} else {
		fmt.Fprintln(w, "D")
	}
}

