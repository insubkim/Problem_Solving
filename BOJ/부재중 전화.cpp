#include <iostream>

using namespace std;

int main() {
  int N,L,D;
  cin >> N >> L >> D;

  int song_end_time = L;
  int ring_time = D;
  for (int i = 1; i < N; i++) {
    while (ring_time < song_end_time) ring_time += D;

    if (song_end_time <= ring_time && ring_time < song_end_time + 5)  break;
    song_end_time += L + 5;
  }
  while (ring_time < song_end_time) ring_time += D;
  
  cout << ring_time << endl;
}