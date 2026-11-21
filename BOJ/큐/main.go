package main

import "bufio"
import "fmt"
import "os"

func main() {
	var r *bufio.Reader = bufio.NewReader(os.Stdin)
	var w *bufio.Writer = bufio.NewWriter(os.Stdout)
	
	defer w.Flush()

	{
		var s MyQueue
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
			case "front":
				var v int
				var ok bool
				
				v, ok = s.Front().(int)
				if ok {
					fmt.Fprintf(w, "%d\n", v)
				} else {
					fmt.Fprintf(w, "-1\n")
				}
			case "back":
				var v int
				var ok bool
				
				v, ok = s.Back().(int)
				if ok {
					fmt.Fprintf(w, "%d\n", v)
				} else {
					fmt.Fprintf(w, "-1\n")
				}
			}
		}
	}
}

type MyQueue struct {
	queue  []interface{}
}

func New() *MyQueue {
	var s MyQueue

	s.queue = make([]interface{}, 0)

	return &s
}

func (s *MyQueue)Push(v interface{}) {
	s.queue = append(s.queue, v)
}

func (s *MyQueue)Pop() interface{}{
	var l int
	var v interface{}

	l = len(s.queue)

	if (l == 0) { return nil }

	v = s.Front()
	s.queue = s.queue[1:]

	return v
}

func (s *MyQueue)Empty() bool {
	return len(s.queue) == 0
}

func (s *MyQueue)Front() interface{} {
	var l int

	l = len(s.queue)

	if (l == 0) { return nil }

	return s.queue[0]
}

func (s *MyQueue)Back() interface{} {
	var l int

	l = len(s.queue)

	if (l == 0) { return nil }

	return s.queue[l - 1]
}

func (s *MyQueue)Size() int {
	return len(s.queue)
}

