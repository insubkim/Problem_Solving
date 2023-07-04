#include <string>
#include <vector>
#include <algorithm>
#include <string.h>

using namespace std;

int N;

bool    cmp(string a, string b){
    if (a[N] == b[N]){
        return strcmp(a.c_str(), b.c_str()) < 0 ? 1 : 0;
    }else{
        return a[N] < b[N];
    }
}

vector<string> solution(vector<string> strings, int n) {
    vector<string> answer = strings; 
    N = n;
    sort(answer.begin(), answer.end(), cmp);
    return answer;
}

#include <iostream>
int main(){
    vector<string> a = {"sun", "bed", "car"};
    vector<string> b = solution(a, 1);
    for (auto x : b){
        std::cout << x << std::endl;
    }
}