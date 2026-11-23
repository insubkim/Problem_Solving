package main

import "bufio"
import "fmt"
import "os"
import "slices"

func main() {
	var r *bufio.Reader
	var w *bufio.Writer

	r = bufio.NewReader(os.Stdin)
	w = bufio.NewWriter(os.Stdout)
	defer w.Flush()

	//testRune()

	{
		var input string
		var s []rune 
		var suffix []string
		var i int

		s = make([]rune, 0, 1000)
		suffix = make([]string, 0, 1000)

		fmt.Fscanf(r, "%s", &input)
		s = []rune(input)
		
		for i = 0; i < len(s); i++ {
			suffix = append(suffix, string(s[i:]))
		}
	
		slices.Sort(suffix)
		
		for i = 0; i < len(suffix); i++ {
			fmt.Fprintf(w, "%s\n", suffix[i])
		}
	}
}


func testRune() {
	var s []rune 
	var suffix []string
	var i int

	s = make([]rune, 0, 1000)
	suffix = make([]string, 0, 1000)
	
	s = []rune("baekjoon")

	for i = 0; i < len(s); i++ {
		suffix = append(suffix, string(s[i: len(s)]))
	}

	fmt.Printf("%s\n", s)
	for i = 0; i < len(suffix); i++ {
		fmt.Printf("suffix-> %s\n", suffix[i])
	}
	os.Exit(1)
}

