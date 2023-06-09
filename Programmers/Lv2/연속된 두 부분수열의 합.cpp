#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> s, int k) {
    vector<int> a;
    int sum = 0;
    int len = (int)s.size() + 1;
    int p,q;
    int j = 0;
    for (int i = 0; i < (int)s.size(); i++){
        sum += s[i];
        while (sum > k && j <= i){
            sum -= s[j];
            j++;
        }
        if (sum == k){
            if (len > i - j + 1){
                p = j;
                q = i;
                len = i - j + 1;
            }
        }
    }
    a.push_back(p);
    a.push_back(q);
    return a;
}