#include <string>
#include <vector>

using namespace std;

string solution(int n) {
    string a = "";
    while (n){
        if (n-- % 2){
            a+="수";
        }else{
            a+="박";
        }
    }
    return a;
}