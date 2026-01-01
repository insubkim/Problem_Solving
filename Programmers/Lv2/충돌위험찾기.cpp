#include <string>
#include <vector>

using namespace std;

void    set_robot(vector<vector<int>> points, vector<vector<int>> routes, vector<int[3]> &robots)
{
    for (auto &x: routes)
    {
        int start = x[0];
        int end = x[1];

        int coord[3];

        coord[0] = points[start][0];
        coord[1] = points[start][1];

        coord[2] = end;

        robots.push_back(coord);
    }
}

int check_crash(vector<int[3]> &robots)
{
    int map[101][101] = {0,};

    for (auto &x: robots)
    {
        if (x[0] == -1) continue ;
        
        map[x[0]][x[1]]++;
    }

    int crash_cnt = 0;
    for (int i = 1; i < 102; i++)
    {
        for (int j = 1; j < 102; j++)
        {
            if (map[i][j] > 1)
                crash_cnt++;
        }   
    }

    return crash_cnt;
}

bool    check_end(vector<int[3]> &robots)
{
    bool end = true;

    for (auto &x: robots)
    {
        if (x[0] != -1)
            return false;
    }

    return end;
}

void move_robots(vector<vector<int>> points, vector<vector<int>> routes, vector<int[3]> &robots) 
{
    // 로봇 이동
    // 이미 목적지면, 목적지 업데이트. 끝났으면 -1 로

    //r 이동 이후, c 이동

    for (auto &x: robots)
    {
        if (x[0] == -1) continue;

        int end[2];
        end[0] = points[x[2]][0];
        end[1] = points[x[2]][1];

        if (x[0] != end[0]) // r 이동
        {
            x[0] = x[0] < end[0] ? x[0] + 1 : x[0] - 1; 
        }
        else if (x[1] != end[1]) // c 이동
        {
            x[1] = x[1] < end[1] ? x[1] + 1 : x[1] - 1; 
        }

        if (x[0] == end[0] && x[1] == end[1]) // 목적지
        {
            // 다음 목적지 찾고 업데이트
            if (routes.size() == x[2])
                x[0] = -1;
            else
                x[2] = x[2] + 1;
        }
    }

}

int solution(vector<vector<int>> points, vector<vector<int>> routes) 
{
    int answer = 0;


    // 로봇 매 초 마다 이동. map에 기록
    // map 에 충돌 확인. 1 보다 큰지 확인
    // 충돌 횟수 카운트

    int crash_cnt = 0;

    vector<int[3]> robots;
    set_robot(points, routes, robots);
    crash_cnt += check_crash(robots);

    int robot_size = routes.size();
    while (check_end(robots) == false)
    {
        move_robots(points, routes, robots);
        
        crash_cnt += check_crash(robots);
    
    }

    answer += crash_cnt;
    return answer;
}

//TODO 움직이고 바로 x[0] = -1 로 업데이트하면 안됨.