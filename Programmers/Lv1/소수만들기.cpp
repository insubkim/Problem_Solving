#include <vector>
#include <iostream>
using namespace std;

int solution(vector<int> n) {
    int a = 0;
    int arr[1001] = {0, };
    for (int i = 2; i * i < 1001; i++){
        for (int j = 1; j * i < 1001; j++){
            arr[i * j] = 1;
        }
    }
    for (int i = 0; i < (int)n.size(); i++){
        for (int j = i + 1; j < (int)n.size(); j++){
            for (int k = j + 1; k < (int)n.size(); k++){
                if (arr[n[i] + n[j] +n[k]] == 0)
                    a++;
            }
        }   
    }
    return a;
}