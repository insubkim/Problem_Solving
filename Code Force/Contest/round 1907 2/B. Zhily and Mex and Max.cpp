#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int t;
int n;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> t;

    while (t-- > 0) {
        cin >> n;
        
        vector<long long> arr;
        set<int> s;

        for (int i = 0; i < n; i++) {
            int v;
            cin >> v;
            if (s.find(v) == s.end()) {
                arr.push_back(v);
                s.insert(v);
            }
        }

        sort(arr.begin(), arr.end());
        
        int arr_size = arr.size();

        long long _max = arr[arr_size - 1];
        long long _min = 0;
        long long _sum = 0;

        arr.insert(arr.begin(), _max);
        arr.pop_back();

        for (int i = 0; i < arr_size; i++) {
            if (_min == arr[i]) {
                _min++;
                if (_min == _max) {
                    _min++;
                } 
            }
            // cout << _min << " " << _max << '\n';
            _sum += _min + _max;
        }

        for (int i = arr_size; i < n; i++) {
            _sum += _min + _max;
        }

        cout << _sum << '\n';

    }
}