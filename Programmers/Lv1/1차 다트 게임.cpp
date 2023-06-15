#include <string>
#include <cmath>

using namespace std;


/*
"점수|보너스|[옵션]"으로 이루어진 문자열 3세트.
예) 1S2D*3T

점수는 0에서 10 사이의 정수이다.
보너스는 S, D, T 중 하나이다.
옵선은 *이나 # 중 하나이며, 없을 수도 있다.
*/

int solution(string d) {
    int a[3] = {0,};
    int j = 0;
    int score;
    char bonus;
    char option = 0;
    for (int i = 0; i < (int)d.size(); i++){
        score = 0;
        while ('0' <= d[i] && d[i] <= '9')
            score = score * 10 + d[i++] - '0'; 
        bonus = d[i];
        if (i + 1 < (int)d.size() && (d[i + 1] == '*' || d[i + 1] == '#'))
            option = d[++i];
        if (bonus == 'D'){
            score = pow(score, 2);
        }else if (bonus == 'T'){
            score = pow(score, 3);
        }
        if (option == '*'){
            score = score * 2;
            if (j)
                a[j - 1] = a[j - 1] * 2;
        }else if (option == '#'){
            score = -score;
        }
        a[j++] = score;
        option = 0;
    }
    score = a[0] + a[1] + a[2];
    return score;
}