#include <iostream>

using namespace std;

int dp[101][100001] = {0, }; 

int main() {
    int N,K;

    cin >> N >> K;
    
    // 무게, 가치
    int item[101][2] = {0, };

    for (int i = 1; i <= N; i++) {
        cin >> item[i][0] >> item[i][1];
    }

    // 점화식
    // 핵심 아이디어 : i 번째 물건을 넣을기 뺄지를 판단하여 최댓값을 구한다.
    // i 번째 물건까지 고려했을때 배낭 용령이 w 일때 최댓값 계산
    // dp[i][w]
    // if w < w[i] : 현재 i 번쨰 아이템이 배낭 용량을 초과함.
    //  dp[i][w] = dp[i-1][w]
    // else
    //  if dp[i-1][w] < dp[i-1][w - w[i]] + v[i]
    //      dp[i][w] = dp[i-1][w - w[i]] + v[i]
    //  else 
    //      dp[i][w] = dp[i - 1][w]


    for (int i = 1; i <= N; i++) { // N번째 item 까지 배낭에 추가   
        for (int j = 1; j <= K; j++) { // 배낭 무게
            if (j < item[i][0]) { // 배낭 무게보다 item 무게가 클때.
                dp[i][j] = dp[i - 1][j];
                continue;
            }

            if (dp[i - 1][j] > dp[i - 1][j - item[i][0]] + item[i][1])
                dp[i][j] =  dp[i - 1][j];
            else 
                dp[i][j] =  dp[i - 1][j - item[i][0]] + item[i][1];
        }
    }

    cout << dp[N][K] << endl;
}