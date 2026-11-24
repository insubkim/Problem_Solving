package main

import "bufio"
import "fmt"
import "io"
import "os"

func main() {
	var r *bufio.Reader
	var w *bufio.Writer

	r = bufio.NewReader(os.Stdin)
	w = bufio.NewWriter(os.Stdout)
	defer w.Flush()

	// test()

	for ;; {
		var s string
		var lower int
		var upper int
		var digit int
		var space int
		var err error
	
		s, err =  r.ReadString('\n')
		if err != nil {
			if err != io.EOF { fmt.Fprintf(w, "returned err - %s\n", err) }
			return
		}

		var c rune
		for _, c = range s {
			if isLower(c) { 
				lower++ 
			} else if isUpper(c) { 
				upper++ 
			} else if isDigit(c) {
				digit++
			} else if isWhiteSpace(c) {
				space++
			}
		}
		space--
		fmt.Fprintf(w, "%d %d %d %d\n", lower, upper, digit, space)
	}
}

func isLower(c rune) bool {
	return 'a' <= c && c <= 'z'	
}


func isUpper(c rune) bool {
	return 'A' <= c && c <= 'Z'	
}

func isDigit(c rune) bool {
	return '0' <= c && c <= '9'
}

func isWhiteSpace(c rune) bool {
	return c == '\t' || c == '\n' || c == '\v' || c == '\f' || c == '\r' || c == ' '
}

func test() {
	fmt.Printf("테스트 시작\n")
	{
		var s string
		var lower int
		var upper int
		var digit int
		var space int

		s = "안녕1하ㅁa세 c요AAㅕㅕㅕㅕㅋㅁㅇ나ㅓ밪당ㅂI"
		var lower_want = 2
		var upper_want = 3
		var digit_want = 1
		var space_want = 1

		var c rune
		for _, c = range s {
			if isLower(c) { 
				lower++ 
			} else if isUpper(c) { 
				upper++ 
			} else if isDigit(c) {
				digit++
			} else if isWhiteSpace(c) {
				space++
			}
		}
		err := fmt.Sprintf("실패 [%s]\n%d %d %d %d", s, lower, upper, digit, space)
		if lower != lower_want { assert(err) }
		if upper != upper_want { assert(err) }
		if digit != digit_want { assert(err) }
		if space != space_want { assert(err) }

	}



	fmt.Printf("테스트 통과\n")
	os.Exit(0)
}

func assert(s string) {
	fmt.Printf("테스트 실패 - %s\n", s)
	os.Exit(1)
}
