#include <string>
#include <vector>

using namespace std;

int solution(vector<int> v) {
    int a = 0;
    for (int t = 0; t < (int)v.size(); t++){
        if (v[t] == 1 && t >= 3){
            if (v[t - 1] == 3 && v[t - 2] == 2 && v[t - 3] == 1){
                v.erase(v.begin() + t - 3, v.begin() + t + 1);
                a++;
                t = t - 4;
            }
        }
    }
    return a;
}

#include <iostream>
int main(){
    vector <int> l = {1,2,1,2,3,1,3,1};
    int k = solution(l);
    cout << k << endl;
    return 0;
}