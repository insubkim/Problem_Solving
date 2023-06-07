#include <string>
#include <vector>

using namespace std;

string solution(string s, string skip, int index) {
    string alpha;
    for (int i = 0; i < 26; i++){
        if (string::npos == skip.find(i + 'a')){
            alpha.push_back(i + 'a');
        }
    }
    for (int i = 0; i < (int)s.size(); i++){
        s[i] = alpha[((int)alpha.find(s[i]) + index) % (int)alpha.size()];
    }
    return s;
}

#include <iostream>

int main(){
    string a = solution("aukks", "wbqd", 5);
    cout << a << endl;
    return 0;
}