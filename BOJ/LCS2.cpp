#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// A 의 i 번째, B 의 j 번째 문자까지 비교했을때 가장 긴 공통 부분 수열
// 문자열의 부분 수열 : 순서를 유지하면서 특정 원소 생략해서 만들수있는 문자열
int dp[1001][1001];

// 문제 접근
// 완전 탐색
// A 의 i 번째와 B의 j 번째까지 문자열 비교
// 같으면 A i-1, B j -1 번째에 +1
// 다르면 
//      A i-1, B j 
//      A i, B j -1 
// 중 큰 값 사용 
// A 의 i+1번째와 B의 j+1번째까지 문자열 비교 할때 반복되는 구조 발견
// LSC(i, j) -> LSC(i-1, j -1) +1 or LSC(i, j-1), LSC(i, j-1)
// 재귀로 해결 가능
// 기존에 이미 계산한 값을 또 계산중. 메모리제이션 사용가능
// 큰 문제가 작은 반복되는 문제로 쪼개지고 
// 작은 문제들을 메모리에 저장해서 재활용 함. 
// -> DP

int main(void) {
    string A, B;

    cin >> A >> B;

    int a_len = A.size();
    int b_len = B.size();

    for (int i = 1; i <= a_len; i++) {
        for (int j = 1; j <= b_len; j++) {
            char a = A[i - 1];
            char b = B[j - 1];
            if (a == b) {
                dp[i][j] = dp[i - 1][j - 1] + 1; 
            }
            else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    int aa_len = a_len;
    int bb_len = b_len;
    string LCS;
    // 뒤에서 부터 A, B 문자 비교
    // 같으면 
    //      해당 문자 선택, aa_len--, bb_len--
    // 다르면 
    //      d[aa_len-1][bb_len], d[aa_len][bb_len-1] 중 큰 값 선택
    //      해당 인덱스 감소
    while (aa_len > 0 && bb_len > 0) {
        if (A[aa_len - 1] == B[bb_len - 1]) {
            LCS.push_back(A[aa_len - 1]);
            aa_len--;
            bb_len--;
        }
        else {
            if (dp[aa_len - 1][bb_len] >= dp[aa_len][bb_len - 1]) {
                aa_len--;
            } else {
                bb_len--;
            }
        }
    }

    reverse(LCS.begin(), LCS.end());

    cout << dp[a_len][b_len] << '\n';
    cout << LCS << '\n';

    return 0;
}