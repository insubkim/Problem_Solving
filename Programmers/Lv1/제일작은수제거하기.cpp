#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// vector<int> solution(vector<int> arr) {
//     int m = 0;
//     for (int i = 1; i (int)arr.size(); i++){
//         if (arr[m] > arr[i]){
//             m = i;
//         }
//     }
//     arr.erase(arr.begin() + m);
//     if (arr.size() == 0){
//         arr.push_back(-1);
//     }
//     return arr;
// }

vector<int> solution(vector<int> a){
    int m = *min_element(a.begin(), a.end());
    m = find(a.begin(), a.end(), m) - a.begin();
    a.erase(a.begin() + m);
    return a.size() > 0 ? a : a.push_back(-1);
}
