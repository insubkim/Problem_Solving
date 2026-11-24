package main

import "bufio"
import "fmt"
import "os"
import "strings"

func main() {
	r := bufio.NewReader(os.Stdin)
	w := bufio.NewWriter(os.Stdout)

	defer w.Flush()


	for ;; {
		var found bool
		var s string
		var err error

		s, err = r.ReadString('\n')
		if err != nil || strings.HasPrefix(s, "EOI") { return }

		found = strings.Contains(strings.ToLower(s), strings.ToLower("Nemo"))

		if found {
			fmt.Fprintf(w, "Found\n")
		} else {
			fmt.Fprintf(w, "Missing\n")
		}
	}
}
