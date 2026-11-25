package main

import "bufio"
import "fmt"
import "os"

func main() {
	r := bufio.NewReader(os.Stdin)
	w := bufio.NewWriter(os.Stdout)
	defer w.Flush()

	var n int

	type wh struct {
		w int
		h int
		rank int
	}
	var whs []wh

	fmt.Fscan(r, &n)
	for i := 1; i <= n; i++ {
		var w int
		var h int
		var wh wh
		fmt.Fscan(r, &w, &h)
		wh.w = w
		wh.h = h
		wh.rank = -1
		whs = append(whs, wh)
	}

	for i := 0; i < n; i++ {
		var rank int
		
		rank = 1
		for j := 0; j < n; j++ {
			if whs[j].w > whs[i].w && whs[j].h > whs[i].h {
				rank++
			}
		}
		fmt.Fprintf(w, "%d ", rank)
	}
	fmt.Fprintf(w, "\n")

}

