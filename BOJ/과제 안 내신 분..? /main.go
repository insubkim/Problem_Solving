package main

import "os"
import "fmt"
import "bufio"

func main() {
	r := bufio.NewReader(os.Stdin)
	w := bufio.NewWriter(os.Stdout)

	defer w.Flush()

	var s [51]bool

	for i := 0; i < 28; i++ {
		var k int

		fmt.Fscan(r, &k)
		s[k] = true
	}

	for i := 1; i <= 30; i++ {
		if s[i] { continue }

		fmt.Fprintf(w, "%d\n", i)
	}
}
