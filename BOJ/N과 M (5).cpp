#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// N 까지의 수 중 M 개 선택
int N, M;

// 수열로 만들 문자 세트
vector<int> nums;

// 선택한 수
int selected[10];

// 수열
int seq[10];

void    solve(int round) {
    if (round == M){
        for (int i = 1; i <= M; i++) {
            cout << nums[seq[i]] << ' ';
        }
        cout << '\n';
        return ;
    }

    for (int i = 1; i <= N; i++){
        if (selected[i]) {
            continue ;
        }
        selected[i] = 1;
        seq[round + 1] = i;
        solve(round + 1);

        selected[i] = 0;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> N >> M;

    nums.push_back(0);
    
    for (int i = 1; i <= N; i++) {
        int n;
        cin >> n;
        nums.push_back(n);
    }

    sort(nums.begin(), nums.end());

    solve(0);

    return 0;
}