#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <string>

using namespace std;

int t;
int n;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> t;

    while (t-- > 0)
    {
        cin >> n;
        
        string a;
        string b;

        cin >> a >> b;
        a.insert(a.begin(), ' ');
        b.insert(b.begin(), ' ');

        int total_open = 0;
        for (int i = 1; i <= n; i++) {
            if (a[i] == '(') total_open++;
            if (b[i] == '(') total_open++;
        }

        if (total_open != n) {
            cout << "NO" << '\n';
            continue;
        }
        
        int a_need_open = n/2;
        int b_need_open = n/2;
        int a_bal = 0;
        int b_bal = 0;

        bool suc = true;
        for (int i = 1; i <= n; i++) {
            char aa = a[i];
            char bb = b[i];

            if (aa == '(' && bb == '(') 
            {
                a_need_open--;
                b_need_open--;
                a_bal++;
                b_bal++;
            } else if (aa == ')' && bb == ')') {
                a_bal--;
                b_bal--;
            } else {
                if (a_need_open > 0 && a_bal + 1 >= 0) {
                    a_bal++;
                    b_bal--;
                    a_need_open--;
                } else {
                   b_bal++;
                   a_bal--;
                   b_need_open--; 
                }
            }
            if (a_bal < 0 || b_bal < 0) {
                suc = false;
                break;
            }
            int remain = n - i;
            if (a_bal > remain || b_bal > remain) {
                suc = false;
                break;    
            }
        }
        // cout << a_open << ' ' << a_close << ' ' << b_open << ' ' << b_close << '\n';
        if (suc && a_bal == 0 && b_bal == 0 && a_need_open == 0 && b_need_open == 0) {
            cout << "YES" << '\n';
        } else {
            cout << "NO" << '\n';
        }

    }
}