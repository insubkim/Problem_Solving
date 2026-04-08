#include <iostream>
#include <queue>

using namespace std;

int n;
int student_select[100001];
int indegree[100001];

int solve() {
    // indegree 초기화
    for (int i = 1; i <= n; i++) {
        indegree[i] = 0;
    }

    // 각 노드의 진입차수 계산
    for (int i = 1; i <= n; i++) {
        indegree[student_select[i]]++;
    }

    queue<int> q;

    // indegree 0인 학생들은 팀이 될 수 없음
    for (int i = 1; i <= n; i++) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }

    int no_team = 0;

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        no_team++;

        int next = student_select[cur];
        indegree[next]--;

        if (indegree[next] == 0) {
            q.push(next);
        }
    }

    return no_team;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        cin >> n;

        for (int i = 1; i <= n; i++) {
            cin >> student_select[i];
        }

        cout << solve() << '\n';
    }

    return 0;
}