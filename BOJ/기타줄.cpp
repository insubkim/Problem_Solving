#include <iostream>
#include <cmath>

using namespace std;

int main() {
  int N, M;
  int pack = 6006;//piece 최대는 1000, 따라서 pack max는 6000
  int piece = 1001;

  cin >> N >> M;

  for (int i = 0; i < M; i++) {
    int tmp1, tmp2;
    cin >> tmp1 >> tmp2;
    pack = min(pack, tmp1);
    piece = min(piece, tmp2);
  }

  pack = min(pack, piece * 6); //pack 사는게 더 손해일때 값 수정 

  //pack 구매
  int price = (N / 6) * pack;
  //pack 사는게 이득일지 piece 사는게 이득일지 판단 후 구매
  price += min(pack, (N % 6) * piece);

  cout << price <<endl;
}