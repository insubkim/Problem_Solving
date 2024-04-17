#include <cassert>
#include <iostream>
#include <string>
#include <cmath>
#include <vector>

using namespace std;

int N,K;
vector<string> vocab;
int max_vocab;

char alpha[26];

void solve(int selected, int cnt) {
  if (K == cnt) {
    int teached_vocab = 0;

    for (int i = 0; i < N; i++) {
      bool teached = true;
      for (int j = 4; j < vocab[i].size() - 4; j++) {
        char c = vocab[i][j];
        if (alpha[c - 'a']) continue ;
        teached = false;
        break ;
      }
      if (teached) teached_vocab++;
    }

    max_vocab = max(max_vocab, teached_vocab);
    return ;
  }
  
  for (int i = selected; i < 26; i++) {
    if (alpha[i]) continue;
    alpha[i] = 1;
    solve(selected + 1, cnt + 1);
    alpha[i] = 0;
  }
}

int main() {
  cin >> N >> K;

  for (int i = 0; i < N; i++) {
    string in;
    cin >> in;
    vocab.push_back(in);
  }
  
  alpha['a' - 'a'] = 1;
  alpha['n' - 'a'] = 1;
  alpha['t' - 'a'] = 1;
  alpha['i' - 'a'] = 1;
  alpha['c' - 'a'] = 1;

  if (K >= 5) solve(0, 5);

  cout << max_vocab << endl;

}