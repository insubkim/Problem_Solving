package main

import "fmt"
import "os"
import "bufio"

const (
	green = iota
	yello
	red
)

func gcd(a int, b int) int {
	for b != 0 {
		a, b = b, a%b
	}
	return a
}

func lcm(a int, b int) int {
	if a == 0 || b == 0 {
		return 0
	}
	return (a * b) / gcd(a, b)
}

func solution(signals [][]int) int {
    var total_lcm int
	var cycle []int
	var s []int
	var t int
	var i int

	total_lcm = 1
	cycle = make([]int, len(signals))
	
	for i, s = range signals {
		fmt.Printf("%v\n", s)
		cycle[i] = s[0] + s[1] + s[2] 
		total_lcm = lcm(total_lcm, cycle[i])
	}

	for t = 1; t < total_lcm; t++ {
		var all_y bool

		all_y = true
		for i, s = range signals {
			var g   int
			var y   int
			var pos int

			g, y = s[0], s[1]
			pos = (t - 1) % cycle[i]

			if !(g <= pos && pos < g+ y) {
				all_y = false
				break 
			}
		}

		if all_y { return t }
	}

	return -1
}

func read_int(r *bufio.Reader, w *bufio.Writer) int {
	var v int
	var err error
	
	_, err = fmt.Fscan(r, &v)
	if err != nil { 
		fmt.Fprintf(w, "error - %s\n", err.Error())
		w.Flush()
		os.Exit(1)
	}
	return v
}

func test_case(w *bufio.Writer) {
	var res int 
	var c [][]int

	c = make([][]int, 3)
	c[0] = []int{3,3,3}
	c[1] = []int{5,4,2}
	c[2] = []int{2,1,2}


	res = solution(c)

	fmt.Fprintf(w, "test result %d\n", res)
	w.Flush()
}

func main() {
	var r *bufio.Reader
	var w *bufio.Writer
	var signals [][]int
	var ret int

	r = bufio.NewReader(os.Stdin)
	w = bufio.NewWriter(os.Stdout)
	defer w.Flush()

	test_case(w)

	{
		var traffic_light int
		var green_t       int
		var yellow_t      int
		var red_t         int
		var i             int 

		traffic_light = read_int(r, w)
		
		signals = make([][]int, traffic_light)

		for i = 0; i < traffic_light; i++ {
			green_t = read_int(r, w)
			yellow_t = read_int(r, w)
			red_t = read_int(r, w)

			signals[i] = []int{green_t, yellow_t, red_t}
		}
	}

	
	ret = solution(signals)
	fmt.Fprintf(w, "ret => %d\n", ret)
}
