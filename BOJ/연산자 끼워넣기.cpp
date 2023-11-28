#include <iostream>
#include <vector>
#include <utility>

using namespace std;

int arr_size;
int result_max, result_min;
bool set = false;

vector<int> arr;

int oPlus, oMinus, multiple, divide;
vector<pair<int, int> > operators;

void  input(){
  cin >> arr_size;

  for (size_t i = 0; i < arr_size; i++){
    int val;
    cin >> val;
    arr.push_back(val);
  }

  cin >> oPlus >> oMinus >> multiple >> divide;
  for (size_t i = 0; i < oPlus; i++)  operators.push_back(make_pair(0, 0));
  for (size_t i = 0; i < oMinus; i++)  operators.push_back(make_pair(1, 0));
  for (size_t i = 0; i < multiple; i++)  operators.push_back(make_pair(2, 0));
  for (size_t i = 0; i < divide; i++)  operators.push_back(make_pair(3, 0));

}

// + - X /
void  solve(int cnt, int sum){
  if (cnt == (int)operators.size()) {
    if (!set) {
      result_max = sum;
      result_min = sum;
    }
    if (result_max < sum) result_max = sum;
    if (result_min > sum) result_min = sum;
  } else {
    for (size_t i = 0; i < operators.size(); i++){
      if (operators[i].second){
        operators[i].second = 1;
        
        operators[i].second = 0;
      }
    }
  }
}

int main(){
  input();
  solve(0, 0);

  cout << result_max << endl;
  cout << result_min << endl;
}