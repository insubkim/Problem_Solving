package main

import "bufio"
import "fmt"
import "os"

func main() {
	var r *bufio.Reader = bufio.NewReader(os.Stdin)
	var w *bufio.Writer = bufio.NewWriter(os.Stdout)
	
	defer w.Flush()

	{
		var s Mystack
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

type Mystack struct {
	stack  []interface{}
}

func New() *Mystack {
	var s Mystack

	s.stack = make([]interface{}, 0)

	return &s
}

func (s *Mystack)Push(v interface{}) {
	s.stack = append(s.stack, v)
}

func (s *Mystack)Pop() interface{}{
	var l int
	var v interface{}

	l = len(s.stack)

	if (l == 0) { return nil }

	v = s.Top()
	s.stack = s.stack[:l - 1]

	return v
}

func (s *Mystack)Empty() bool {
	return len(s.stack) == 0
}

func (s *Mystack)Top() interface{} {
	var l int

	l = len(s.stack)

	if (l == 0) { return nil }

	return s.stack[l - 1]
}

func (s *Mystack)Size() int {
	return len(s.stack)
}

