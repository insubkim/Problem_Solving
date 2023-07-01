#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(vector<string> s) {
    int i = find(s.begin(), s.end(), "KIM") - s.begin();
    return "김서방은 " + to_string(i) + "에 있다";
}
