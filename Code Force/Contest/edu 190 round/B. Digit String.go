package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	var r *bufio.Reader = bufio.NewReader(os.Stdin)
	var w *bufio.Writer = bufio.NewWriter(os.Stdout)
	defer w.Flush()

	var t int

	fmt.Fscan(r, &t)

	for t > 0 {
		var s string
		fmt.Fscan(r, &s)

		var erase_cnt int = 1e9

		var s_len int = len(s)
		var prefix []int = make([]int, s_len+1)
		var suffix []int = make([]int, s_len+1)
		var erase_four int = 0

		for _, c := range s {
			if c == '4' {
				erase_four++
			}
		}

		for i := 0; i < s_len; i++ {
			if s[i] == '1' || s[i] == '3' {
				prefix[i+1] = 1
			}
			prefix[i+1] += prefix[i]
		}

		for i := s_len - 1; i >= 0; i-- {
			suffix[i] = suffix[i+1]
			if s[i] == '2' {
				suffix[i]++
			}
		}

		for i := 0; i <= s_len; i++ {

			m := prefix[i] + suffix[i] + erase_four
			erase_cnt = min(m, erase_cnt)
		}

		fmt.Fprintf(w, "%d\n", erase_cnt)

		t--
	}

}

/*
끝이 4 인 경우
14,24,34,44

아래 경우는
12 32
1,3 을 삭제하거나
끝 2를 삭제해야함.

1. 먼저 4는 전부 삭제
2. 1,3 삭제할지 2를 삭제할지에 대한 최솟값 계산
	기준점 인덱스 i 설정
	i 이전은 1,3 삭제
	i 부터는 2 삭제
	인뎃스 i 에 따른 계산값 저장

	쵯솟값 계산
*/
