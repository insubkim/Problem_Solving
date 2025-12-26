#include <string>
#include <vector>
#include <iostream>

using namespace std;

void    delete_char(char map[][52], char c)
{
    for (int j = 0; j < 52; j++)
    {
        for (int i = 0; i < 52; i++)
        {
            map[j][i] = map[j][i] == c ? 0 : map[j][i];
        }  
    }
}


int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

#define VISITED 1

void bfs(char map[][52], char c, int y, int x)
{
    // bound check
    if (y < 0 || y > 51 || x < 0 || x > 51)
        return ;

    // do not visit twice
    if (map[y][x] == VISITED)
        return ;
    
    // cannot visit other space
    if (map[y][x] != c && map[y][x] != 0)
        return ;
    
        
    if (map[y][x] == c)
    {
        map[y][x] = VISITED;
        return ;
    }
    map[y][x] = VISITED;

    for (int i = 0; i < 4; i++)
    {
        bfs(map, c, dy[i] + y, dx[i] + x);
    }
}

int solution(vector<string> storage, vector<string> requests) {
    int answer = 0;

    char map[52][52] = {0,};

    int j = 1;
    for (auto &x: storage)
    {
        int i = 1;
        for (auto &y : x)
        {
            map[j][i++] = y;
        }
        j++;
    }

    // 단일 문자
    // 테두리만 돌아서 삭제
    // 복수 문자
    // 전부 순회 후 삭제
    for (auto &x: requests)
    {
        if (x.size() > 1) 
            delete_char(map, x[0]);
        else 
        {
            bfs(map, x[0], 0, 0);

            for (int j = 0; j < 52; j++)
                for (int i = 0; i < 52; i++)
                    if (map[j][i] == VISITED)
                        map[j][i] = 0;
        }
    }

    int zeroes = 0;

    for (int j = 1; j <= storage.size(); j++)
    {
        for (int i = 1; i <= storage[0].size(); i++)
        {
            zeroes += map[j][i] == 0 ? 1 : 0;
            if (map[j][i]) cout << map[j][i];
            else cout <<" ";    
        }
        cout << endl;
    }

    answer = storage.size() * storage[0].size() - zeroes;
    return answer;
}

int main()
{
    vector<string> s = {"AZWQY", "CAABX", "BBDDA", "ACACA"};
    vector<string> r = {"A", "BB", "A"};
    int a = solution(s, r);
    cout << a << endl;
}