#include <cassert>
#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <cstring>

using namespace std;

int N,K;
int vocab[51];
int max_vocab;
int alpha;

int solve(int depth, int idx) {
  int teached_vocab = 0;
  if (depth == K - 5) {

    for (int i = 0; i < N; i++) {
      if ((vocab[i] & alpha) == vocab[i]) teached_vocab++;  
    }
    max_vocab = max(max_vocab, teached_vocab);
    return max_vocab;
  }

  for (int i = idx; i < 26; i++) {
    if (alpha & (1 << i)) continue;
    alpha |= 1 << i;
    max_vocab = max(solve(depth + 1, idx + 1), teached_vocab);
    alpha &= ~(1 << i);
  }
  return max_vocab;
}

int main() {
  cin >> N >> K;

  for (int i = 0; i < N; i++) {
    string str;
    cin >> str;
    vocab[i] = 0;
    for (auto c : str) {
      vocab[i] |= 1 << (c - 'a');
    }
  }

  alpha |= 1 << ('a' - 'a');
  alpha |= 1 << ('n' - 'a');
  alpha |= 1 << ('t' - 'a');
  alpha |= 1 << ('i' - 'a');
  alpha |= 1 << ('c' - 'a');
  
  if (K < 5) solve(0, 0);

  cout << max_vocab << endl;

}