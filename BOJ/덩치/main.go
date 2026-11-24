package main

import "bufio"
import "fmt"
import "os"
import "sort"

func main() {
	r := bufio.NewReader(os.Stdin)
	w := bufio.NewWriter(os.Stdout)
	defer w.Flush()

	var n int
	var rank [51]int

	type wh struct {
		i int
		w int
		h int
	}
	var whs []wh

	fmt.Fscan(r, &n)
	for i := 1; i <= n; i++ {
		var w int
		var h int
		var wh wh
		fmt.Fscan(r, &w, &h)
		wh.i = i
		wh.w = w
		wh.h = h
		whs = append(whs, wh)
	}

	// 정렬
	sort.Slice(whs, func(i, j int) bool {
		if whs[i].w > whs[j].w && whs[i].h > whs[j].h {
			return true
		}
		return false
	})

	// rank 저장



	// rank 출력

}
