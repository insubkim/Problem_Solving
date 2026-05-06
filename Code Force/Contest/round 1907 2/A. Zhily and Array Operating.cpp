#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int t;
int n;
long long arr[2 * 100000 + 1];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> t;

    while (t-- > 0) {
        cin >> n;
        
        for (int i = 1; i <= n; i++) {
            cin >> arr[i];
        }

        for (int i = n - 1; i >= 1; i--) {
            if (arr[i] + arr[i + 1] > arr[i]) {
                arr[i] = arr[i] + arr[i + 1];
            }
        }

        int positive = 0;
        for (int i = 1; i <= n; i++) {
            if (arr[i] > 0) 
                positive++;
        }
        cout << positive << '\n';
    }

}