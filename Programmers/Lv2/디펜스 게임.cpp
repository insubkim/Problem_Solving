#include <string>
#include <vector>
#include <queue>


using namespace std;

int solution(int n, int k, vector<int> enemy) {
    priority_queue<int> h;
    size_t i = 0;
    while ((k > 0 ||  n >= enemy[i]) && i < enemy.size()){
        if (n >= enemy[i]){
            h.push(enemy[i]);
            n -= enemy[i];
        }else{
            k--;
            if (!h.empty() && h.top() > enemy[i]){
                n += h.top();
                n -= enemy[i];
                h.pop();
            }
        }
        i++;
    }
    return i;
}