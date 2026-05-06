package main

import (
	"fmt"
	"os"
	"bufio"
)

func main() {
	r := bufio.NewReader(os.Stdin)
	w := bufio.NewWriter(os.Stdout)
	defer w.Flush()

	var t int
	fmt.Fscan(r, &t)
	for i := 0; i < t; i++ {
		var word string
		fmt.Fscan(r, &word)

		var word_len int

		word_len = len(word)
		if word_len <= 10 {
			fmt.Fprintf(w, "%v\n", word)
		} else {
			fmt.Fprintf(w, "%c%v%c\n", word[0], word_len - 2, word[word_len - 1])
		}
	}


}