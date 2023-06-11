#include <string>
#include <vector>

using namespace std;

string solution(string s, int n) {
    for (int i = 0; i < (int)s.size(); i++){
        if (s[i] == ' ')
            continue;
        else if ('a' <= s[i] && s[i] <= 'z'){
            s[i] = (s[i] - 'a' + n) % 26 + 'a';
        }else if ('A' <= s[i] && s[i] <= 'Z'){
            s[i] = (s[i] - 'A' + n) % 26 + 'A';
        }else{
            s[i] += n;
        }
    }
    return s;
}