#include <string>
#include <vector>

using namespace std;

/*

세 숫자가 모두 다르다면 a + b + c 점을 얻습니다.
세 숫자 중 어느 두 숫자는 같고 나머지 다른 숫자는 다르다면 (a + b + c) × (a2 + b2 + c2 )점을 얻습니다.
세 숫자가 모두 같다면 (a + b + c) × (a2 + b2 + c2 ) × (a3 + b3 + c3 )
*/



int solution(int a, int b, int c) {
    if (a != b && b != c && a != c){
        return a + b + c;
    }else if (a == b && b == c){
        return (a + b + c) *(a*a + b*b + c*c) * (a*a*a + b*b*b + c*c*c);
    }else{
        return (a + b + c) * (a*a + b*b + c*c);
    }
}