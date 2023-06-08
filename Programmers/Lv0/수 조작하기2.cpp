#include <string>
#include <vector>

using namespace std;

string solution(vector<int> n) {
    string a = "";
    for (int i = 1; i < (int)n.size(); i++){
        if (n[i] - n[i - 1] == 1){
            a.push_back('w');
        }else if (n[i] - n[i - 1] == -1){
            a.push_back('s');
        }else if (n[i] - n[i - 1] == 10){
            a.push_back('d');
        }else{
            a.push_back('a');
        }
    }
    return a;
}