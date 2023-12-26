#include <iostream>

using namespace std;

int solve(int n, int battery) {
  if (n == 0)
    return battery;
  if (n % 2 && battery != 0) return solve(n / 2, battery);
  return solve(n - 1, battery + 1);
}

int solution(int n)
{
  int ans = solve(n, 0);  
  return ans;
}