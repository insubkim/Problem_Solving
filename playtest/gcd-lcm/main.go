package main

import "fmt"
import "os"
import "bufio"

// 최소공약수 
func gcd(a int, b int) int {
	for b > 0 {
		a, b = b, b%a
	}
	return a
}

// 최대 공배수
func lcm(a int, b int) int {
	if a == 0 || b == 0 {
		return 0
	}
	return (a * b) / gcd(a, b)
}

func main() {
	var r *bufio.Reader
	var w *bufio.Writer
	var a int
	var b int
	var res int

	r = bufio.NewReader(os.Stdin)
	w = bufio.NewWriter(os.Stdout)
	defer w.Flush()

	fmt.Fscan(r, &a, &b)
	res = gcd(a, b)
	fmt.Fprintf(w, "gcd => %d\n", res)

	res = lcm(a, b)
	fmt.Fprintf(w, "lcm=> %d\n", res)

}
