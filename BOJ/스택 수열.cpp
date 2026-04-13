#include <iostream>
#include <string>
#include <stack>
#include <vector>

using namespace std;

int main() {
    int N;
    vector<int> v;

    cin >> N;

    for (int i = 1; i <= N; i++) {
        int a;
        cin >> a;
        v.push_back(a);
    }

    vector<char> vv;
    stack<int> s;
    int cur = 1;
    for (auto x: v) {
        
        // stack input 비교
        // 비었을때 cur push
        // 같으면 pop 
        // 다르면 push

        if (s.empty()) {
            s.push(cur);
            cur++;
            vv.push_back('+');
        }

        while (s.top() != x) {
            if (cur > N) {
                cout << "NO" << endl;
                return 0;
            }

            s.push(cur);
            cur++;
            vv.push_back('+');
        }
        

        vv.push_back('-');
        s.pop();
    }   

    for (auto x : vv) {
        cout << x << '\n';
    }
}