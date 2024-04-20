#include <iostream>
#include <cmath>
#include <cassert>

using namespace std;

double get_dist(int ax, int ay, int bx, int by) {
  return sqrt(pow(bx - ax, 2) + pow(by - ay, 2));
}

int main() {
  // 일직선 확인
  // 둘레 구하기

  int ax,ay;
  int bx,by;
  int cx,cy;
  cin >> ax >> ay;
  cin >> bx >> by;
  cin >> cx >> cy;

  double inc1 = ((double)by - ay) / ((double)bx - ax);
  double inc2 = ((double)cy - by) / ((double)cx - bx);
  
  if (inc1 == inc2) {
    cout << -1 << endl;
    return 0;
  }

  //3가지 경우
  //a-b a-c
  double round1 = (get_dist(ax, ay, bx, by) + get_dist(ax, ay, cx, cy)) * 2;

  //a-b b-c
  double round2 = (get_dist(ax, ay, bx, by) + get_dist(bx, by, cx, cy)) * 2;

  //a-c b-c
  double round3 = (get_dist(ax, ay, cx, cy) + get_dist(bx, by, cx, cy)) * 2;

  double min_round = min(round1, min(round2, round3));
  double max_round = max(round1, max(round2, round3));
  
  cout << max_round - min_round << endl;
}