#include <string>
#include <vector>

using namespace std;

/*
1단계 new_id의 모든 대문자를 대응되는 소문자로 치환합니다.
2단계 new_id에서 알파벳 소문자, 숫자, 빼기(-), 밑줄(_), 마침표(.)를 제외한 모든 문자를 제거합니다.
3단계 new_id에서 마침표(.)가 2번 이상 연속된 부분을 하나의 마침표(.)로 치환합니다.
4단계 new_id에서 마침표(.)가 처음이나 끝에 위치한다면 제거합니다.
5단계 new_id가 빈 문자열이라면, new_id에 "a"를 대입합니다.
6단계 new_id의 길이가 16자 이상이면, new_id의 첫 15개의 문자를 제외한 나머지 문자들을 모두 제거합니다.
     만약 제거 후 마침표(.)가 new_id의 끝에 위치한다면 끝에 위치한 마침표(.) 문자를 제거합니다.
7단계 new_id의 길이가 2자 이하라면, new_id의 마지막 문자를 new_id의 길이가 3이 될 때까지 반복해서 끝에 붙입니다.

*/

string solution(string n) {
    for (int i = 0; i < (int)n.size(); i++){
        if ('A' <= n[i] && n[i] <= 'Z')
            n[i] |= 32;
    }
    for (int i = 0; i < (int)n.size(); i++){
        if ('a' <= n[i] && n[i] <= 'z')
            continue;
        if ('0' <= n[i] && n[i] <= '9')
            continue;
        if (n[i] == '-' || n[i] == '_' || n[i] == '.')
            continue;
        n.erase(i, 1);
        i--;
    }
    if ((int)n.size() > 1){
        for (int i = 1; i < (int)n.size(); i++){
            if (n[i - 1] == '.' && n[i] == '.'){
                n.erase(i, 1);
                i--;
            }
        }
    }
    while ((int)n.size() > 0 && n[0] == '.'){
        n.erase(0, 1);
    }
    while ((int)n.size() > 0 && n[(int)n.size() - 1] == '.'){
        n.erase((int)n.size() - 1, 1);
    }
    if ((int)n.size() == 0)
        n = "a";
    if ((int)n.size() > 15){
        n.erase(15, 1000);
    }
    while ((int)n.size() > 0 && n[(int)n.size() - 1] == '.'){
        n.erase((int)n.size() - 1, 1);
    }
    while ((int)n.size() < 3){
        n.push_back(n.back());
    }
    return n;
}

#include <iostream>

int main(){
    string k = solution(".S.1.");
    cout << k << endl;
    return 0;
}