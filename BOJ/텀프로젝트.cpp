#include <iostream>
#include <vector>

#include <string.h>

using namespace std;

// 사람 수
int n;

// 각 학생이 선택한 팀원
int student_select[100001];
// 팀 소속 여부
int student_team[100001];

int solve(void) {
    // 각 선수 팀에 소속되어 있는지 확인
    // 소속 안되어있으면 소속 시도.
    // 마지막 선택된 학생이 처음 선택한 학생 골랐는지 확인
    memset(student_team, 0, sizeof(student_team));
    for (int i = 1; i <= n; i++) {
        if (student_team[i]) {
            continue ;
        }

        vector<int> team;
        team.push_back(i);
        int visited[100001] = {0,};

        while (true) {
            int last = team.back();
            int last_select = student_select[last];

            if (visited[last]) {
                break ;
            }
            
            if (last_select == team[0]) {
                for (auto &x: team) {
                    student_team[x] = true;
                }
                break ;
            }

            team.push_back(last_select);
            visited[last] = true;
        }
    }

    int no_team = 0;
    for (int i = 1; i <= n; i++) {
        if (!student_team[i]) {
            no_team++;
        }
    }

    return no_team;
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> student_select[i];
        }
        int no_team;
        no_team = solve();
        
        cout << no_team << endl;
    }
    
    return 0;
}