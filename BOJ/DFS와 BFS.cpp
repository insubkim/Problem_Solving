#include <bits/stdc++.h>

using namespace std;

int N, M, V;

vector<int> adj[1001];
int visited[1001];

void    dfs(int cur_node)
{
    // 현제 노드 방문
    cout << cur_node << " ";
    visited[cur_node] = 1;

    // 1 ~ N 까지 차례로 방문
    // dfs 실행
    
    for (auto &x: adj[cur_node])
    {
        if (visited[x] == 0)
            dfs(x);
    }
}

void    bfs(int cur_node)
{
    queue<int> visit_list;
    // 현재 노드 큐에 추가
    visit_list.push(cur_node);
    visited[cur_node] = 1;
    cout << cur_node << " ";


    // 큐 확인
    // 큐에서 맨앞빼고 전부 방문 처리
    // 이전에 방문 안했으면 queue 추가
    while (visit_list.empty() == false)
    {
        cur_node = visit_list.front();
        visit_list.pop();

        for(auto &x : adj[cur_node])
        {
            if (visited[x])
                continue;
            
            visited[x] = 1;
            cout << x << " ";
            
            visit_list.push(x);
        }

    }   
}

int main()
{
    cin >> N >> M >> V;

    for (int i = 0; i < M; i++)
    {
        int a,b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for (int i = 1; i <= N; i++)
        sort(adj[i].begin(), adj[i].end());

    dfs(V);
    cout << "\n";

    memset(visited, 0, sizeof(visited));
    bfs(V);
    cout << "\n";

}