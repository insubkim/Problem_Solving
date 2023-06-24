#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> d, int budget) {
    int answer = 0;
    sort(d.begin(), d.end());
    for (auto x : d){
        budget -= x;
        if (budget >= 0){
            answer++;
        }else{
            break ;
        }
    }
    return answer;
}