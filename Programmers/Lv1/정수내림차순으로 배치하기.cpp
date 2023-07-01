#include <string>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

// long long solution(long long n) {
//     int arr[10] = {0,};
//     while (n > 0){
//         arr[n % 10]++;
//         n /= 10;
//     }
//     for (int i = 9; i >= 0; i--){
//         while (arr[i]-- > 0)
//             n = n * 10 + i;
//     }
//     return n;
// }

long long solution(long long n) {
    string s = to_string(n);
    sort(s.begin(), s.end(), greater<char>());
    return stoll(s);
}