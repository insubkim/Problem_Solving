#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    if (n < 0)
            return -1;
    if (n == 1)
        return 0;
    int i = 0;
    while (i < 500){
        n = n % 2 ? n * 3 + 1 : n / 2;
        i++;
        if (n == 1){
            return i;
        }
    }
    return -1;
}

#include <iostream>
int main(){
    int k = solution(626331);
    cout << k << endl;
}