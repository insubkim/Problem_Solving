#include <string>
#include <vector>
#include <cmath>

using namespace std;

int solution(vector<int> players, int m, int k) {
    int answer = 0;

    // (n x m) 명 이상 (n + 1) x m 명 미만

    // m 명 늘면 서버 증설 필요 
    // k 서버 대여 시간

    vector<int> added_server(24, 0);

    for (int i = 0; i < players.size(); i++)
    {
        int current_server = 1;
        // update current server
        for (int j = i; j > i - k & j >= 0; j--)
        {
            current_server += added_server[j];
        }

        // check server stat
        if ((current_server) * m <= players[i])
        {
            // add server
            // cal mininum server to add
            int need_server = players[i] / m + 1;
            added_server[i] = need_server - current_server;
        }
    }

    for (auto &x: added_server)
    {
        answer += x;
    }

    return answer;
}