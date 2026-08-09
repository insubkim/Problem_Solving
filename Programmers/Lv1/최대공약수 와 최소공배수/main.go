package main

import "os"
import "fmt"
import "strconv"

func gcd(a int, b int) int {
	for b != 0 {
		a, b = b, a%b
	}
	return a
}

func lcm(a int, b int) int {
	if a == 0 || b == 0 { return 0 }
	return (a * b) / gcd(a, b)
}

func solution(a int, b int) []int {
	var res []int

	res = make([]int, 2)
	res[0] = gcd(a, b)
	res[1] = lcm(a, b)

    return res
}

func main() {
	var a int
	var b int
	var res []int

	a, _ = strconv.Atoi(os.Args[1])
	b, _ = strconv.Atoi(os.Args[2])

	res = solution(a, b)
	fmt.Printf("%d - %d | gcd - %d | lcm - %d\n", a, b, res[0], res[1])	
}
