#include <string>
#include <vector>

using namespace std;
//"aya", "ye", "woo", "ma"
int solution(vector<string> b) {
    int a = 0;
    for (string x : b){
        int i;
        for (i = 0; i < (int)x.size(); i++){
            if (!x.compare(i, 3, "aya") && (i < 3 || x.compare(i - 3, 3, "aya"))){
                i += 2;
            }else if (!x.compare(i, 3, "woo") && (i < 3 || x.compare(i - 3, 3, "woo"))){
                i += 2;
            }else if (!x.compare(i, 2, "ma") && (i < 2 || x.compare(i - 2, 2, "ma"))){
                i += 1;
            }else if (!x.compare(i, 2, "ye") && (i < 2 || x.compare(i - 2, 2, "ye"))){
                i += 1;
            }else{
                break ;
            }
        }
        if (i == (int)x.size())
            a++;
    }
    return a;
}

#include <iostream>

int main(){
    vector<string> b = {"mamaye"};
    int a = solution(b);
    cout << a << endl;
    return 0;
}