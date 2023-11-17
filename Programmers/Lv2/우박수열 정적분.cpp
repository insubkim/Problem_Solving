#include <string>
#include <vector>
#include <iterator>

using namespace std;

vector<double> spaces;//index ~ index + 1 구간의 넓이(사다리꼴 공식)

void  colats(int k){
  int cur = 0;
  int prev = k;
  while (k != 1){
    if (k % 2 == 0){ //짝수
      k /= 2;
    } else { //홀수
      k = k * 3 + 1;
    }
    cur = k;
    spaces.push_back(((double)cur + prev) / 2);
    prev = k;
  }
}



vector<double> solution(int k, vector<vector<int> > ranges) {

  //colats
  colats(k);

  vector<double> answer;
  for (size_t i = 0; i < ranges.size(); i++){
    int start = ranges[i][0];
    int end = spaces.size() + ranges[i][1];
    if (start > end){
      answer.push_back(-1);
      continue;
    }
    double sum = 0;
    while (start != end){
      sum += spaces[start++];
    }
    answer.push_back(sum);
  }
  return answer;
}

#include <iostream>
int main(){
  //[[0,0],[0,-1],[2,-3],[3,-3]]
  vector<vector<int> > ranges;
  vector<int> temp;
  temp.push_back(0);
  temp.push_back(0);
  ranges.push_back(temp);
  temp.clear();
  temp.push_back(0);
  temp.push_back(-1);
  ranges.push_back(temp);
  temp.clear();
  temp.push_back(2);
  temp.push_back(-3);
  ranges.push_back(temp);
  temp.clear();
  temp.push_back(3);
  temp.push_back(-3);
  ranges.push_back(temp);

  //make test case

  vector<double> i = solution(5, ranges);
  for (int j = 0; j < i.size(); j++){
    cout << i[j] << " ";
  }
}