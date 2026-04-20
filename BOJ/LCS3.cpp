#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// A 의 i 번째, B 의 j 번째,  C 의 k 번째 문자까지 비교했을때 가장 긴 공통 부분 수열
// 문자열의 부분 수열 : 순서를 유지하면서 특정 원소 생략해서 만들수있는 문자열
int dp[101][101][101];

// 문제 접근
// 완전 탐색
// A 의 i 번째, B의 j 번째, C의 k 번째까지 문자열 비교
// 같으면 A i-1, B j -1, C k -1 번째에 +1
// 다르면 
//      A i-1, B j, C k 
//      A i-1, B j -1 , C k
//      A i-1, B j, C k - 1
//      A i, B j -1, C k 
//      A i, B j -1, C k -1
//      A i, B j, C k -1 
// 중 큰 값 사용 
// A 의 i+1번째와 B의 j+1번째 C의 k+1번째까지 문자열 비교 할때 반복되는 구조 발견
// LSC(i, j, k) -> LSC(i-1, j -1, k - 1) +1 or LSC(i, j-1, k), LSC(i, j-1, k -1), ...
// 재귀로 해결 가능
// 기존에 이미 계산한 값을 또 계산중. 메모리제이션 사용가능
// 큰 문제가 작은 반복되는 문제로 쪼개지고 
// 작은 문제들을 메모리에 저장해서 재활용 함. 
// -> DP

int main(void) {
    string A, B, C;

    cin >> A >> B >> C;

    int a_len = A.size();
    int b_len = B.size();
    int c_len = C.size();

    for (int i = 1; i <= a_len; i++) {
        for (int j = 1; j <= b_len; j++) {
            for (int k = 1; k <= c_len; k++) {
                char a = A[i - 1];
                char b = B[j - 1];
                char c = C[k - 1];
                if ((a == b) && (b == c)) {
                    dp[i][j][k] = dp[i - 1][j - 1][k - 1] + 1; 
                }
                else {
                    dp[i][j][k] = max({
                        dp[i - 1][j][k],
                        dp[i - 1][j - 1][k],
                        dp[i - 1][j][k - 1],
                        dp[i][j - 1][k],
                        dp[i][j - 1][k - 1],
                        dp[i][j][k - 1]
                    });
                }
            }
        }
    }
    cout << dp[a_len][b_len][c_len] << '\n';
    
    return 0;
}