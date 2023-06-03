#include <string>
#include <vector>

using namespace std;

string solution(string m, string o, int s) {
    string mm = m;
    for (int i = 0; i < (int)o.size(); i++){
        mm[s++] = o[i];
    }
    return (mm);
}

int main(){
    
}