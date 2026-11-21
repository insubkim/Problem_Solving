package common

type Stack interface {
	Push(v interface{})
	Pop() interface{}
	Empty() bool
	Top() interface{}
	Size() int
}
