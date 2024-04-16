#include <iostream>

int main() {
  int arr[101] = {0, };
  int people;
  int rejected;

  std::cin >> people;

  rejected = 0;
  while (people--) {
    int num;
    std::cin >> num;
    if (num > 100 || num < 0) continue ; 
    else if (arr[num]) rejected++;
    arr[num] = 1;
  }
  std::cout << rejected << std::endl;
}