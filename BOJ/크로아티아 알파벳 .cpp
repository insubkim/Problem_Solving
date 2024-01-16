#include <iostream>

using namespace std;


int main() {
  std::string croatia_alpha;

  cin >> croatia_alpha;
  int num = 0;

  for (size_t i = 0; i < croatia_alpha.size(); i++) {
    if (!croatia_alpha.compare(i, 2, "c=", 2) ||\
        !croatia_alpha.compare(i, 2, "c-", 2) ||\
        !croatia_alpha.compare(i, 2, "d-", 2) ||\
        !croatia_alpha.compare(i, 2, "lj", 2) ||\
        !croatia_alpha.compare(i, 2, "nj", 2) ||\
        !croatia_alpha.compare(i, 2, "s=", 2) ||\
        !croatia_alpha.compare(i, 2, "z=", 2)) {
        i++;
    } else if (!croatia_alpha.compare(i, 3, "dz=", 3)) {
      i += 2;
    }
    num++;
  }
  cout << num << endl;
}