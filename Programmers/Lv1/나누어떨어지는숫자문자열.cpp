#include <string>
#include <vector>
#include <algorithm>


using namespace std;

vector<int> solution(vector<int> arr, int divisor) {
    vector<int> a;
    for (auto x : arr){
        if (x % divisor == 0)
            a.push_back(x);
    }
    if (a.size() == 0)
            a.push_back(-1);
    sort(a.begin(), a.end());
    return a;
}