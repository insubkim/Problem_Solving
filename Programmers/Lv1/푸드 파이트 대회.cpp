#include <string>
#include <vector>

using namespace std;

string solution(vector<int> f) {
    string a = "";
    for (int i = 1; i < (int)f.size(); i++){
        f[i] = f[i] / 2;
        for (int j = 1; j <= (int)f[i]; j++){
            a.push_back(i + '0');
        }
    }
    a.push_back('0');
    for (int i = (int)f.size() - 1; i >= 1; i--){
        for (int j = 1; j <= (int)f[i]; j++){
            a.push_back(i + '0');
        }
    }
    return a;
}

