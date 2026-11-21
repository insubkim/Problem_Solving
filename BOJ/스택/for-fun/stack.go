package mystack

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
