#include <string>
#include <vector>

using namespace std;

/* 
 * if fomula is 
 * ax^2 + bx^1 + c = 0
 */
vector<double>  quadraticFormula(double a, double b, double c) {
  vector<double> answer(2);
  answer[0] = (-b + sqrt(pow(b, 2) - 4 * a * c)) / 2;
  answer[1] = (-b - sqrt(pow(b, 2) - 4 * a * c)) / 2;
  return answer;
}

/*
 * x, y are width, legnth
 * brown = 2 * x + 2 * y
 * yello = (x - 2) * (y - 2)
 * 
 * Solving for x in a system of equations
 * x^2 + (brown / 2 - 2) + brown  + yello = 0
 * (brown is always odd)
 * we can solve with quadraticFormula
 */
vector<int> solution(int brown, int yellow) {
    vector<int> answer(2);
    vector<double> equation_values = quadraticFormula(1, -(brown / 2 + 2), brown + yellow);
    answer[0] = equation_values[0];
    answer[1] = equation_values[1];
    return answer;
}

#include <iostream>
int main() {
    vector<int> answer = solution(24, 24);
    cout << answer[0] << " " << answer[1] << endl;
}