#include <string>
#include <vector>

using namespace std;

string solution(string s1, string s2) {
    string a;
    for (int i = 0; i < (int)s1.size(); i++){
        a.push_back(s1[i]);
        a.push_back(s2[i]);
    }
    return a;
}