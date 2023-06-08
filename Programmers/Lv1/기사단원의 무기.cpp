#include <string>
#include <vector>

using namespace std;

int get(int n){
    int r = 0;
    for (int i = 1; i * i <= n; i++){
        if (n % i == 0){
            if (i * i == n){
                r++;
            }else{
                r += 2;
            }
        }
    }
    return r;
}

int solution(int n, int l, int p) {
    int a = 0;
    int k;
    for (int i = 1; i <= n; i++){
        k = get(i);
        if (k > l)
            a += p;
        else
            a += k;
    }
    return a;
}