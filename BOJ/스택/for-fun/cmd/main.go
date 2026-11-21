package main

import "bufio"
import "fmt"
import "os"

import "boj"


func main() {
	var r *bufio.Reader = bufio.NewReader(os.Stdin)
	var w *bufio.Writer = bufio.NewWriter(os.Stdout)
	
	defer w.Flush()

	{
		var s mystack.Mystack
		var t int
		
		fmt.Fscanf(r, "%d", &t)

		for t > 0 {
			var cmd string

			t--
			fmt.Fscan(r, &cmd)

			switch cmd {
			case "push":
				var v int

				fmt.Fscanf(r, "%d", &v)
				s.Push(v)
			case "pop":
				var v int
				var ok bool

				v, ok = s.Pop().(int)
				if ok {
					fmt.Fprintf(w, "%d\n", v)
				} else {
					fmt.Fprintf(w, "-1\n")
				}
			case "size":
				fmt.Fprintf(w, "%d\n", s.Size())
			case "empty":
				if s.Empty() {
					fmt.Fprintf(w, "1\n")
				} else {
					fmt.Fprintf(w, "0\n")
				}
			case "top":
				var v int
				var ok bool
				
				v, ok = s.Top().(int)
				if ok {
					fmt.Fprintf(w, "%d\n", v)
				} else {
					fmt.Fprintf(w, "-1\n")
				}
			}
		}
	}
}
