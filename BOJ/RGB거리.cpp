#include <iostream>
#include <cmath>
#include <string.h>

using namespace std;

int main () {
  int n;
  cin >> n;
  int costs[3] = {0};
  int curr[3];

  while (n--) {
    cin >> curr[0] >> curr[1] >> curr[2];
    int prev_costs[3];
    memcpy(prev_costs, costs, sizeof costs);
    //select R
    costs[0] = min(prev_costs[1], prev_costs[2]) + curr[0];
    //select G
    costs[1] = min(prev_costs[0], prev_costs[2]) + curr[1];
    //select B
    costs[2] = min(prev_costs[0], prev_costs[1]) + curr[2];
  } 
  
  cout << min(costs[0], min(costs[1], costs[2])) << endl;

}