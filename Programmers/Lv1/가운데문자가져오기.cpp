#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string a = "";
    //1(0) - 0
    //2(1) - 01
    //3(2) - 1
    //4(3) - 12
    //5(4) - 2
    //6(5) - 23
    //홀수일 때는 (size - 1) / 2
    //짝수일 때는 위에서 하나더.
    a.push_back(s[(s.size() - 1) / 2]);
    if (s.size() % 2 == 0){
        a.push_back(s[(s.size() - 1) / 2 + 1]);
    }
    return a;
}