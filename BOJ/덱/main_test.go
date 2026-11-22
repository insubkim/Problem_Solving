package main

import "testing"

func TestDeque(t *testing.T) {
	var d *MyDeque

	d = NewDeque()

	for i := 0; i <= 9999; i++ {
		d.PushFront(i)
		d.PushBack(i)
	}

	for i := 9999; i >= 0; i-- {
		v := d.Front().(int)
		d.PopFront()

		if i != v { t.Errorf("Expected %d, but got %d", i, v) }
	}
	
	for i := 9999; i >= 0; i-- {
		v := d.Back().(int)
		d.PopBack()

		if i != v { t.Errorf("Expected %d, but got %d", i, v) }
	}
}
