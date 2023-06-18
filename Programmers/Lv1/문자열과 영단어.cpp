#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int a = 0;
    for (int i = 0; i < (int)s.size(); i++){
        if (isdigit(s[i])){
            a = a * 10 + s[i] - '0';
        }else{
            if (s[i] == 'z'){
                a = a * 10 + 0;
                i += 3; 
            }else if (s[i] == 'o'){
                a = a * 10 + 1;
                i += 2; 
            }else if (s[i] == 't' && s[i + 1] == 'w'){
                a = a * 10 + 2;        
                i += 2; 
            }else if (s[i] == 't'){
                a = a * 10 + 3;        
                i += 4;
            }else if (s[i] == 'f' && s[i] == 'o'){
                a = a * 10 + 4;        
                i += 3;
            }else if (s[i] == 'f' && s[i] == 'i'){
                a = a * 10 + 5;        
                i += 3; 
            }else if (s[i] == 's' && s[i] == 'i'){
                a = a * 10 + 6;        
                i += 2; 
            }else if (s[i] == 's' && s[i] == 'e'){
                a = a * 10 + 7;        
                i += 4;
            }else if (s[i] == 'e' && s[i] == 'i'){
                a = a * 10 + 8;        
                i += 4;
            }else if (s[i] == 'n' && s[i] == 'i'){
                a = a * 10 + 9;        
                i += 3; 
            }
        }
    }
    return a;
}