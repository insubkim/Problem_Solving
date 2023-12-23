#include <string>
#include <vector>
#include <iostream>
#include <unordered_set>

using namespace std;

bool  validateWord(unordered_set<string>& said, const char last_char, const string& word) {
  return said.count(word) || last_char != word.front();
}

vector<int> solution(int n, vector<string> words) {
    unordered_set<string> said;
    char                  last_char = words[0].front();

    for (size_t i = 0; i < words.size(); i++) {
      if (validateWord(said, last_char, words[i])) {
        return {(int)i % n + 1, (int)i / n + 1};
      }
      said.insert(words[i]);
      last_char = words[i].back();
    }
    return {0, 0};
}