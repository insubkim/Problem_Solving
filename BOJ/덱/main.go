package main

import "bufio"
import "fmt"
import "os"

func main() {
	var r *bufio.Reader = bufio.NewReader(os.Stdin)
	var w *bufio.Writer = bufio.NewWriter(os.Stdout)
	
	defer w.Flush()

	{
		var s *MyDeque
		var t int
	
		s = NewDeque()
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
			default:
				assert(false)
			}
			// s.Peek()
		}
	}
}

type MyDeque struct {
	deque    []interface{}
	front    int // front indicates first value index
	// back     int // back is not neccesarry since, back = (front + size) % capacity
	// | 6 | - | - | - | - | 3 | 4 | 5 |
	//                        F
	// B = ( 5 + 4 ) % 8; // 1
	capacity int
	size     int
}

const initialDequeSize = 256

func NewDeque() *MyDeque {
	var s MyDeque

	s.deque = make([]interface{}, initialDequeSize)
	s.capacity = len(s.deque)
		
	return &s
}

func (s *MyDeque)expand() {
	var d []interface{}
	var n int

	d = make([]interface{}, s.capacity * 2)

	n = copy(d, s.deque[s.front:])

	if s.front + s.size > s.capacity {
		copy(d[n:], s.deque[:s.size - n])	
	}

	s.front = 0

	s.deque = d
	s.capacity = len(s.deque)
}

func (s *MyDeque)PushFront(v interface{}) {
	if s.size == s.capacity { s.expand() }

	s.front = (s.front - 1 + s.capacity) % s.capacity
	s.deque[s.front] = v

	s.size++	
}

func (s *MyDeque)PushBack(v interface{}) {
	if s.size == s.capacity { s.expand() }
	
	s.deque[(s.front + s.size) % s.capacity] = v
	
	s.size++	
}

func (s *MyDeque)PopFront() interface{}{
	var v interface{}

	if s.size == 0 { return nil }

	v = s.Front()
	s.deque[s.front] = nil
	s.front = (s.front + 1) % s.capacity
	s.size--

	return v
}

func (s *MyDeque)PopBack() interface{}{
	var v interface{}

	if (s.size == 0) { return nil }

	v = s.Back()
	s.deque[(s.front + s.size - 1) % s.capacity] = nil
	s.size--

	return v
}

func (s *MyDeque)Empty() bool {
	return s.size == 0
}

func (s *MyDeque)Front() interface{} {
	if s.size == 0 { return nil }

	return s.deque[s.front]
}

func (s *MyDeque)Back() interface{} {
	if s.size == 0 { return nil }

	return s.deque[(s.front + s.size - 1) % s.capacity]
}

func (s *MyDeque)Size() int {
	return s.size
}

func (s *MyDeque)Peek() {
	var i int

	fmt.Printf("size : %d, capacity : %d\n", s.size, s.capacity)
	for i = 0; i < s.capacity; i++ {
		fmt.Printf("queue location [%d] [%v]", i, s.deque[i])
		if i == s.front { fmt.Printf(" << Front") }
		if i == (s.front + s.size) % s.capacity { fmt.Printf(" << Back ") }
		fmt.Printf("\n")
	}
}

func assert(c bool) {
	if !c { panic("FAIL") }
}
