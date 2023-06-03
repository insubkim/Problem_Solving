#include <string>
#include <vector>

using namespace std;

string solution(string m, string o, int s) {
    for (int i = 0; i < (int)o.size(); i++){
        m[s++] = o[i];
    }
    return (m);
}

int main(){
    
}