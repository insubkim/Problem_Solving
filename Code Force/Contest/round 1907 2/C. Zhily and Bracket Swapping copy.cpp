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

        int a_open = 0;
        int a_close = 0;
        int b_open = 0;
        int b_close = 0;

        int total_open = 0;
        for (int i = 1; i <= n; i++) {
            if (a[i] == '(') total_open++;
            if (b[i] == '(') total_open++;
        }

        if (total_open != n) {
            cout << 'NO' << '\n';
            break;
        }
        
        int a_need_open = 2/n;
        int b_need_open = 2/n;
        int a_bal = 0;
        int b_bal = 0;

        for (int i = 1; i <= n; i++) {
            // cout << a[i] << ' ' << b[i] << " BEFORE \n";
            if (a[i] != b[i]) {
                
                int aa_open = a_open + (a[i] == '(' ? 1 : 0);
                int aa_close = a_close + (a[i] == ')' ? 1 : 0);
                int bb_open = b_open + (b[i] == '(' ? 1 : 0);
                int bb_close = b_close + (b[i] == ')' ? 1 : 0);

                // cout << aa_open << ' ' << aa_close << '\n';
                // cout << bb_open << ' ' << bb_close << '\n';

                if (aa_open < aa_close || bb_open < bb_close 
                || aa_open - aa_close > n - i || bb_open - bb_close > n - i) {
                    char c = a[i];
                    a[i] = b[i];
                    b[i] = c;
                }
            } 
            // cout << a[i] << ' ' << b[i] << " AFTER \n";

            if (a[i] == '(')    a_open++;
            else                a_close++;

            if (b[i] == '(')    b_open++;
            else                b_close++;

            if (a_open < a_close) break;
            if (b_open < b_close) break;

            if (a_open - a_close > n - i) break; 
            if (b_open - b_close > n - i) break; 
        }
        // cout << a_open << ' ' << a_close << ' ' << b_open << ' ' << b_close << '\n';
        if (a_open == a_close && b_open == b_close) {
            cout << "YES" << '\n';
        } else {
            cout << "NO" << '\n';
        }

    }
}