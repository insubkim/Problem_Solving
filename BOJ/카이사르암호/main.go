package main

import "bufio"
import "fmt"
import "os"

func main() {
	r := bufio.NewReader(os.Stdin)
	w := bufio.NewWriter(os.Stdout)

	defer w.Flush()

	var b []byte
	fmt.Fscanf(r, "%s", &b)

	for i := 0; i < len(b); i++ {
		if b[i] <= 'C' {
			b[i] = b[i] + 23
		} else {
			b[i] = b[i] - 3
		}
	}

	fmt.Fprintf(w, "%s\n", b)

}
