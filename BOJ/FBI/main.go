package main

import "bufio"
import "fmt"
import "io"
import "os"
import "strings"

func main() {
	var r *bufio.Reader
	var w *bufio.Writer

	r = bufio.NewReader(os.Stdin)
	w = bufio.NewWriter(os.Stdout)
	defer w.Flush()

	var fed bool
	var i int
	for i = 1;; i++ {
		var s string
		var err error

		s, err = r.ReadString('\n')
		
		if err != nil {
			if err != io.EOF { fmt.Fprintf(w, "error reading string - %s\n", err.Error()) }
			break	
		}
		
		if strings.Contains(s, "FBI") {
			fmt.Fprintf(w, "%d ", i)
			fed = true
		}
	}
	if fed == false { fmt.Fprintf(w, "HE GOT AWAY!") }
	fmt.Fprintf(w, "\n")
}
