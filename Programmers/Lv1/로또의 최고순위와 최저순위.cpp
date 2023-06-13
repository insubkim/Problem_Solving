#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> l, vector<int> w) {
    vector<int> a;
    int w_arr[46] = {0,};
    for (int i = 0; i < 6; i++){
        w_arr[w[i]]++;
    }
    int low = 0;
    for (int i = 0; i < 6; i++){
        if (w_arr[l[i]]){
            low++;
        }
    }
    a.push_back(6 - (low + w_arr[0]));
    a.push_back(6 - low);
    return a;
}