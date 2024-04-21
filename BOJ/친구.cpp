#include <iostream>
#include <cmath>
#include <cassert>

using namespace std;
bool  is_direct_friend(const int relations[][51], int row, int col) {
  return relations[row][col] && relations[col][row];
} 


bool  is_indirect_friend(const int relations[][51], int cur_row, int cur_col, int N) {
  int target = cur_col;

  //check target is my friend's friend
  for (int col2 = 1; col2 <= N; col2++) {
    //if friend, check his friend is my target friend
    if (is_direct_friend(relations, cur_row, col2)) {
      int friend_row = col2;
      if (is_direct_friend(relations, friend_row, target)) {
        return true;
      }
    }
  }
  return false;
}

int main() {
  int N;
  cin >> N;
  assert(N <= 50);

  int max_friends = 0;
  int relations[51][51];

  for (int i = 1; i <= N; i++) {
    string in;
    cin >> in;
    int j = 1;
    for (auto x : in) {
      assert(x == 'N' || x == 'Y');
      if (x == 'Y')  relations[i][j] = 1;
      else            relations[i][j] = 0;
      j++;
    }
  }


  for (int row = 1; row <= N; row++) {
    int friends = 0;
    //iter col 
    // if Y check other is Y, if other is N check if other is my friend's friend
    for (int col = 1; col <= N; col++) {
      if (col == row) continue ;
      
      if (is_direct_friend(relations, row, col)) { //direct friend
        friends++;
      } else if (is_indirect_friend(relations, row, col, N)) {//indirect friend
        friends++;
      }
    }
    assert(friends <= 50 && friends >= 0);
    max_friends = max(max_friends, friends);
  }

  assert(max_friends <= 50 && max_friends >= 0);
  cout << max_friends << endl;
}