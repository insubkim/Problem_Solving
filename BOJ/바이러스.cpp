#include <bits/stdc++.h>

using namespace std;

int N, M;
vector<int> adj[101];

int affected_cnt;

void    bfs(void)
{
    queue<int> visit_list;
    int visited[101] = {0,};

    // 1번 노드 부터 시작
    visit_list.push(1);
    visited[1] = 1;

    // bfs 로 각 노드 방문 시도
    while (visit_list.empty() == false)
    {
        int cur_node = visit_list.front();
        visit_list.pop();

        for (auto &x: adj[cur_node])
        {
            if  (visited[x]) continue;
            
            visited[x] = 1;
            affected_cnt++;
            visit_list.push(x);
        }
    }

}

int main()
{
    cin >> N >> M;

    for (int i = 0; i < M; i++)
    {
        int a,b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    bfs();

    cout << affected_cnt << endl;
}