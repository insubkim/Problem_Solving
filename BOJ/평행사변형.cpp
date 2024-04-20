#include <iostream>
#include <cmath>
#include <cassert>
#include <printf.h>

using namespace std;

double get_dist(int ax, int ay, int bx, int by) {
  return sqrt(pow(bx - ax, 2) + pow(by - ay, 2));
}

int main() {
  // 일직선 확인
  // 둘레 구하기

  double ax,ay;
  double bx,by;
  double cx,cy;
  cin >> ax >> ay;
  cin >> bx >> by;
  cin >> cx >> cy;

  // 일직선 확인
  if ((by - ay) * (cx - bx) == (bx - ax) * (cy - by)) {
    // cout << -1 << endl;
    printf("%.15lf\n", -1.0);
    return 0;
  }
  if ((ax == bx && ay == by) || (ax == cx && ay == cy) || (cx == bx && cy == by)){
    // cout << -1 << endl;
    printf("%.15lf\n", -1.0);
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
  
  // cout << max_round - min_round << endl;
  printf("%.15lf\n", max_round - min_round);
}