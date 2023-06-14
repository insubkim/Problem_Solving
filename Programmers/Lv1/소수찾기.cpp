#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int a = 0;
    int arr[n + 1] = {0, };
    for (int i = 2; i * i < n + 1; i++){
        for (int j = 1; j * i < n + 1; j++){
            arr[i * j] = 1;
        }
    }
    for (int i = 2; i < n + 1; i++){
        if (arr[i] == 0)
            a++;
    }
    return a;
}