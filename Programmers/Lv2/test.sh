count=1

c++ "최댓값과 최솟값.cpp" 

while [ $count -le 1000 ]
do
  jot -r 10000 -99999 99999 | tr '\n' ' ' | ./a.out;
  ((count++))
done