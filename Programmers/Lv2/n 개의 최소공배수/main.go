package main

import "os"
import "strconv"
import "fmt"

func gcd(a int, b int) int {
	for b > 0 {
		a, b = b, a%b
	}
	return a
}

func lcm(a int, b int) int {
	if a == 0 || b == 0 { return 0 }
	
	return (a * b) / gcd(a, b)
}

func solution(arr []int) int {
	var res int 
	var i int

	res = arr[0]

	for i = 1; i < len(arr); i++ {
		res = lcm(res, arr[i])
	}
	return res
}

func main() {
	var n int 
	var arr []int
	var res int
	var i int

	n, _ = strconv.Atoi(os.Args[1])
	arr = make([]int, n)
	
	for i = 0; i < n; i++ {
		arr[i], _ = strconv.Atoi(os.Args[i + 2])
	}

	res = solution(arr)
	fmt.Printf("%v\n lcm -> %d\n", arr, res)
}
