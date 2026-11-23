package main

import "bufio"
import "fmt"
import "os"

func main() {
	var r *bufio.Reader
	var w *bufio.Writer

	r = bufio.NewReader(os.Stdin)
	w = bufio.NewWriter(os.Stdout)
	defer w.Flush()

	{
		var arr [2001]bool
		var n int
		var i int

		fmt.Fscan(r, &n)
	
		for i = 0; i < n; i++ {
			var v int

			fmt.Fscan(r, &v)
			arr[v + 1000] = true
		}


		for i = 0; i < len(arr); i++ {
			//fmt.Fprintf(w, "i - %d: arr[i] %v\n", i, arr[i])

			if arr[i] { fmt.Fprintf(w, "%d ", i - 1000) }
		}
	}
}

