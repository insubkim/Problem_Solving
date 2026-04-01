#include <iostream>

using namespace std;

// 인덱스에 해당하는 자연수가 소수면 true 
bool is_prime[1000001];

void cal_prime(void) {
    // 처음에는 전부 true
    // 1 은 소수 아님.  
    // 2 부터 1,000,000에 대해 수의 배수이면 false 처리. 
    
    memset(is_prime, true, sizeof(is_prime));
    is_prime[0] = false;
    is_prime[1] = false;

    for (int n = 2; n <= 1000000; n++) {
        int k = n + n;
        while (k <= 1000000) {
            
            is_prime[k] = false;
            k += n;
        }
    }
}

int main() {

    cal_prime();

    int M,N;
    cin >> M >> N;
    for (int i = M; i <= N; i++) {
        if (is_prime[i]) {
            cout << i << endl;
        }
    }

    return 0;
}