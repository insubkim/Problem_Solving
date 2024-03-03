#include <iostream>
#include <cassert>
#include <cmath>
#include <cstring>

using namespace std;

inline bool is_leap_year(int year) {
  return (year % 400 == 0) ||
        (year % 4 == 0 && year % 100 != 0);
}

int main() {
  //y m d
  int s_y, s_m, s_d;
  cin >> s_y >> s_m >> s_d;
  //y m d
  int e_y, e_m, e_d;
  cin >> e_y >> e_m >> e_d;

  //1000 year == gg
  if (e_y > s_y + 1000 || 
    (e_y == s_y + 1000 && e_m > s_m) ||
    (e_y == s_y + 1000 && e_m == s_m && e_d >= s_d)) {
    //(e_y == s_y + 1000 && e_m >= s_m && e_d >= s_d)) {

      cout << "gg" << endl;
      return 0;
  }

  int day = 0;
  
  for (int i = 1; s_y + i < e_y; i++) {
    if (is_leap_year(s_y + i)) day += 366;
    else day += 365;
  }
  
  int days[13] = {
    0, 
    31, 28, 31, 30, 31, 30, 
    31, 31, 30, 31, 30, 31
  };

  if (s_y == e_y) {
    day -= s_d;
    for (int i = 0; s_m + i < e_m; i++) {
      day += days[s_m + i];
      if (is_leap_year(s_y) && s_m + i == 2) day++;
    }
    day += e_d;
  } else {
    day -= s_d;
    for (int i = 0; s_m + i < 13; i++) {
      day += days[s_m + i];
      if (is_leap_year(s_y) && s_m + i == 2) day++;
    }
    for (int i = 1; i < e_m; i++) {
      day += days[i];
      if (is_leap_year(e_y) && i == 2) day++;
    }
    day += e_d;
  }
  cout << "D-" << day << endl;
}