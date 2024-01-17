#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int get_times(int val, int times) {
  int rtn = 0;
  while (val) {
    rtn += pow(val % 10, times);
    val /= 10;
  }  
  return rtn;
}

int main() {
  int start, times;

  cin >> start >> times;

  vector<int> arr;
  int val = start;
  do {
    arr.push_back(val);
    val = get_times(val, times);
  } while (find(arr.begin(), arr.end(), val) == arr.end());

  cout << find(arr.begin(), arr.end(), val) - arr.begin() << endl;

}