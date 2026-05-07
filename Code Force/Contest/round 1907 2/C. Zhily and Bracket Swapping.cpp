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

        int low = 0;
        int high = 0;
        bool    suc = true;

        for (int i = 1; i <= n; i++) {
            char aa = a[i];
            char bb = b[i];

            if (aa == '(' && bb == '(') 
            {
                high++;
                low++;
            } else if (aa == ')' && bb == ')') { 
                high--;
                low--;
            } else { 
                if (high < 1) {
                    suc = false;
                    break ;
                }

                high--;
                low++;
                
                int h = high;
                int l = low;

                high = max(l, h);
                low = min(l, h);
            }

            if (low < 0 || high < 0) {
                suc = false;
                break ;
            }
        }
        if (suc && low == 0 && high == 0) {
            cout << "YES" << '\n';
        } else {
            cout << "NO" << '\n';
        }
    }
}