#include <iostream>
#include <array>
#include <algorithm>

using namespace std;

int main(){
  int n;
  cin >> n;
    
  std::array<std::array<int, 2>, 100000> arr;

  for_each(arr.begin(), arr.begin() + n, [] (std::array<int, 2>& val) {
    cin >> val[0] >> val[1];
  });
  
  sort(arr.begin(), arr.begin() + n);
  
  for_each(arr.begin(), arr.begin() + n, [] (std::array<int, 2>& val) {
    cout << val[0] << " " << val[1] << "\n";
  });
}