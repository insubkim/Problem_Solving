#include <string>
#include <vector>

using namespace std;

string solution(string my_string, int k) {
    string a;
    while (k--) a += my_string;
    return a;
}