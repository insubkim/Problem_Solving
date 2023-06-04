#include <string>
#include <vector>

using namespace std;

string solution(string c) {
    string a;
    int mode = 0;
    for (int i = 0; i < (int)c.size(); i++){
        if (mode){
            if (c[i] != '1' && i % 2){
                a.push_back(c[i]);    
            }else if (c[i] == '1'){
                mode = 0;
            }
        }else{
            if (c[i] != '1' && i % 2 == 0){
                a.push_back(c[i]);    
            }else if (c[i] == '1'){
                mode = 1;
            }
        }
    }
    if (a.size() == 0){
        a += "EMPTY";
    }
    return a;
}