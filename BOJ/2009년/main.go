package main

import "fmt"
import "os"
import "bufio"

var dayOfWeek = []string{
	 "Monday", 
	 "Tuesday", 
	 "Wednesday", 
	 "Thursday", 
	 "Friday", 
	 "Saturday", 
	 "Sunday",
}

type DayOfWeek_ string

const (
	 Monday    DayOfWeek_ = "Monday" 
	 Tuesday   DayOfWeek_ = "Tuesday"
	 Wednesday DayOfWeek_ = "Wednesday"
	 Thursday  DayOfWeek_ = "Thursday"
	 Friday    DayOfWeek_ = "Friday"
	 Saturday  DayOfWeek_ = "Saturday"
	 SunDay    DayOfWeek_ = "Sunday"
)

func main() {
	var curWeekDay int
	var targetDay int
	var targetMonth int
	var curDay int
	var curMonth int
	var r *bufio.Reader
	var w *bufio.Writer
	var err error

	// 2009 starts from thursday
	curWeekDay = 3

	r = bufio.NewReader(os.Stdin)
	w = bufio.NewWriter(os.Stdout)
	defer w.Flush()

	_, err = fmt.Fscanf(r, "%d %d", &targetDay , &targetMonth)
	if err != nil { 
		fmt.Printf("error input\n") 
		os.Exit(1)
	}

	// 1 3 5 7 8 10 12 : 31
	// 2 : 28
	// 4 6 9 11 : 30
	curDay = 1
	curMonth = 1
	for curDay != targetDay || curMonth != targetMonth {
		curDay++
		curWeekDay++
		curWeekDay %= 7
		//fmt.Fprintf(w, "%d-%d\n", curMonth, curDay)
		if curDay > 31 &&
		   (curMonth == 1  ||
		    curMonth == 3  ||
		    curMonth == 5  ||
		    curMonth == 7  ||
		    curMonth == 8  ||
		    curMonth == 10 ||
		    curMonth == 12) {
			//fmt.Fprintf(w, "31 month change %d-%d\n", curMonth, curDay)
			curDay = 1
			curMonth++
		} else if curDay > 30 && 
			      (curMonth == 4 ||
			       curMonth == 6 ||
			       curMonth == 9 ||
			       curMonth == 11) {
			//fmt.Fprintf(w, "30 month change %d-%d\n", curMonth, curDay)
			curDay = 1
			curMonth++
		} else if curDay > 28 && curMonth == 2 {
			//fmt.Fprintf(w, "28 month change %d-%d\n", curMonth, curDay)
			curDay = 1
			curDay = 1
			curMonth++
		}

		if (curMonth > 12 || curDay > 31) {
			fmt.Fprintf(w, "something very wrong %d-%d\n", curMonth, curDay)	
			os.Exit(2)
		}
	}
	//fmt.Fprintf(w, "%d-%d\n", curMonth, curDay)

	fmt.Fprintf(w, "%s\n", dayOfWeek[curWeekDay]);
}
