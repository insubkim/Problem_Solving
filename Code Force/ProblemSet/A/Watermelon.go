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

	var weigh int
	fmt.Fscan(r, &weigh)

	if weigh%2 != 0 || weigh == 2 {
		fmt.Fprintf(w, "NO\n")
	} else {
		fmt.Fprintf(w, "YES\n")
	}

}
