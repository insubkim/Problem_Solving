#include <string>
#include <vector>
#include <stack>
#include <iostream>

using namespace std;

#define LEFT  -1
#define RIGHT +1

#define DEBUG 1

vector<stack<int>> stack_box(int n, int w)
{
    vector<stack<int>> container;
    int container_col = -1;
    int dir = RIGHT;
    
    for (int i = 0; i < n; i++)
    {
        // 매 루프 시작시 container_col 증가/ 감소
        container_col += dir;
        
        if (container_col > w - 1)
        {
            container_col--;   
            dir = LEFT;
        }
        else if (container_col < 0)
        {
            container_col++;
            dir = RIGHT;
        } 
        

        if (i < w)
           container.push_back(stack<int>());
        
        container[container_col].push(i + 1);
    }
    return container;
}

int pop_box(int num, vector<stack<int>> &container)
{
    int k = 1;

    for (auto &x: container)
    {
        int cnt = 0;

        if (DEBUG) cout << "stack [" << k++ << "] " << endl;

        while (!x.empty())
        {
            if (DEBUG) cout << x.top() << endl;

            if (x.top() == num)
                return cnt + 1;
            x.pop();
            cnt++;
        }
    }
    return -1;
}

int solution(int n, int w, int num) {
    int answer = 0;
    
    // n 상자 수
    // w 가로 길이 
    // num 상자 번호
    
    // 상자 넣기
    vector<stack<int>> container = stack_box(n, w);
    
    // num 위 상자 수 찾기 
    answer = pop_box(num, container);
    
    return answer;
}


int main()
{
    cout << solution(22, 6, 8) << endl;
}