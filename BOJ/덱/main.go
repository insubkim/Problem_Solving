package main

import "bufio"
import "fmt"
import "os"

func main() {
	var r *bufio.Reader = bufio.NewReader(os.Stdin)
	var w *bufio.Writer = bufio.NewWriter(os.Stdout)
	
	defer w.Flush()

	{
		var s MyDeque
		var t int
		
		fmt.Fscanf(r, "%d", &t)

		for t > 0 {
			var cmd string

			t--
			fmt.Fscan(r, &cmd)

			switch cmd {
			case "push_front":
				var v int

				fmt.Fscanf(r, "%d", &v)
				s.PushFront(v)
			case "push_back":
				var v int

				fmt.Fscanf(r, "%d", &v)
				s.PushBack(v)
			case "pop_front":
				var v int
				var ok bool

				v, ok = s.PopFront().(int)
				if ok {
					fmt.Fprintf(w, "%d\n", v)
				} else {
					fmt.Fprintf(w, "-1\n")
				}
			case "pop_back":
				var v int
				var ok bool

				v, ok = s.PopBack().(int)
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
			s.Peek()
		}
	}
}

type MyDeque struct {
	deque    []interface{}
	front    int // front indicates first value index
	back     int // back indicates next index to be inserted on back, 
	             // the main reason to separate front, back concept is to distinguish whether deque is empty
				 // if front, back indicates the actual position of value, 
				 // on empty state of deque, we need flag for empty state. check ex1, ex2
				 // ex1) | - | - | - |
				 //       F,B       F == B 
				 // ex2) | 1 | - | - |
				 //       F,B       F == B 

	capacity int
	size     int
}

func New() *MyDeque {
	var s MyDeque
	var size int

	size = 256

	s.deque = make([]interface{}, size)
	s.capacity = size

	return &s
}

func (s *MyDeque)expand() {
	var d []interface{}

	d = make([]interface{}, len(s.deque) * 2)

	if s.front < s.back {
		copy(d, s.deque)
	} else {
		d = append(d, s.deque[s.front:])
		d = append(d, s.deque[:s.back + 1])
		s.front = 0
		s.back = s.size - 1
		// when deque is empty
		if s.back < 0 { s.back = 1 }
	}

	s.deque = d
	s.capacity = len(s.deque)
}

func (s *MyDeque)PushFront(v interface{}) {
	if s.size + 1 == s.capacity { s.expand() }

	if s.front == s.back {
		s.back++
	} else if s.front == 0 {
		s.front = s.capacity - 1
	} else {
		s.front--
	}

	if s.front == s.back {
		fmt.Printf("something is very wrong deque front == back on inserting\n")
		os.Exit(12)
	}

	s.deque[s.front] = v

	s.size++	
}

func (s *MyDeque)PushBack(v interface{}) {
	if s.size + 1 == s.capacity { s.expand() }
	
	if s.back == s.capacity - 1 {
		s.back = 0
	} else {
		s.back++
	}

	if s.front == s.back {
		fmt.Printf("something is very wrong deque front == back on inserting\n")
		os.Exit(12)
	}

	s.deque[s.back] = v
	s.size++	
}

func (s *MyDeque)PopFront() interface{}{
	var l int
	var v interface{}

	l = len(s.deque)

	if (l == 0) { return nil }

	v = s.Front()
	s.deque = s.deque[:l - 1]

	return v
}

func (s *MyDeque)PopBack() interface{}{
	var l int
	var v interface{}

	l = len(s.deque)

	if (l == 0) { return nil }

	v = s.Front()
	s.deque = s.deque[:l - 1]

	return v
}

func (s *MyDeque)Empty() bool {
	return len(s.deque) == 0
}

func (s *MyDeque)Front() interface{} {
	var l int

	l = len(s.deque)

	if (l == 0) { return nil }

	return s.deque[l - 1]
}

func (s *MyDeque)Back() interface{} {
	var l int

	l = len(s.deque)

	if (l == 0) { return nil }

	return s.deque[l - 1]
}

func (s *MyDeque)Size() int {
	return len(s.deque)
}

func (s *MyDeque)Peek() {
	var i int

	fmt.Printf("size : %d, capacity : %d\n", s.size, s.capacity)
	for i = 0; i < s.capacity; i++ {
		fmt.Printf("queue location [%d] [%v]", i, s.deque[i])
		if i == s.front { fmt.Printf(" << Front") }
		if i == s.back { fmt.Printf(" << Back ") }
		fmt.Printf("\n")
	}
}


