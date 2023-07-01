#include <string>
#include <vector>
#include <math.h>

using namespace std;

// long long solution(long long n) {
//     for (long long i = 1; i * i <= n; i++){
//         if (i * i == n){
//             return (i + 1) * (i + 1);
//         }
//     }
//     return -1;
// }


long long solution(long long n) {
    long long a = sqrt(n);
    return powl(a, 2) == n ? powl(a + 1, 2) : -1 ;

}
