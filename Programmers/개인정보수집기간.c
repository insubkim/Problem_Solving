#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
// terms_len은 배열 terms의 길이입니다.
// privacies_len은 배열 privacies의 길이입니다.
// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.



/*
today는 "YYYY.MM.DD" 형태로 오늘 날짜를 나타냅니다.
1 ≤ terms의 길이 ≤ 20
terms의 원소는 "약관 종류 유효기간" 형태의 약관 종류와 유효기간을 공백 하나로 구분한 문자열입니다.
약관 종류는 A~Z중 알파벳 대문자 하나이며, terms 배열에서 약관 종류는 중복되지 않습니다.
유효기간은 개인정보를 보관할 수 있는 달 수를 나타내는 정수이며, 1 이상 100 이하입니다.

1 ≤ privacies의 길이 ≤ 100
privacies[i]는 i+1번 개인정보의 수집 일자와 약관 종류를 나타냅니다.
privacies의 원소는 "날짜 약관 종류" 형태의 날짜와 약관 종류를 공백 하나로 구분한 문자열입니다.
날짜는 "YYYY.MM.DD" 형태의 개인정보가 수집된 날짜를 나타내며, today 이전의 날짜만 주어집니다.
privacies의 약관 종류는 항상 terms에 나타난 약관 종류만 주어집니다.
today와 privacies에 등장하는 날짜의 YYYY는 연도, MM은 월, DD는 일을 나타내며 점(.) 하나로 구분되어 있습니다.
2000 ≤ YYYY ≤ 2022
1 ≤ MM ≤ 12
MM이 한 자릿수인 경우 앞에 0이 붙습니다.
1 ≤ DD ≤ 28
DD가 한 자릿수인 경우 앞에 0이 붙습니다.
파기해야 할 개인정보가 하나 이상 존재하는 입력만 주어집니다

*/

int* solution(const char* today, const char* terms[], size_t terms_len, const char* privacies[], size_t privacies_len) {
    // /"2022.05.19"
    int today_i = atoi(today);
    today_i = today_i * 100 + atoi(today + 5);
    today_i = today_i * 100 + atoi(today + 8);
    int p_i[privacies_len];
    //p_i에 파기해야하면 1 저장 아니면 0 저장
    int valid_date;
    char t;
    int mon;
    int len = 0;
    for (size_t i = 0; i < privacies_len; i++){
        t = privacies[i][strlen(privacies[i]) - 1];
        for (int k = 0; k < terms_len; k++){
            if (terms[k][0] == t){
                mon = atoi(terms[k] + 2);
                break ;
            } 
        }
        valid_date =  atoi(privacies[i]);
        if (atoi(privacies[i] + 5) + mon > 12){
            valid_date = valid_date + (atoi(privacies[i] + 5) + mon) / 12;
            valid_date = valid_date * 100 + (atoi(privacies[i] + 5) + mon) % 12;    
        }else{
            valid_date = valid_date * 100 + atoi(privacies[i] + 5) + mon;
        }
        //20200101
        //12
        //202101 01
        //202012 28
        //202012 28
        if (atoi(privacies[i] + 8) == 1){
            //1월 일경우
            if (valid_date % 100 == 1){
                valid_date = (valid_date - 100) * 100 + 1128;
            }else{
                valid_date--;
                valid_date = valid_date * 100 + 28;
            }
            //valid_date--;
            //valid_date = valid_date * 100 + 28;
        }else{
            valid_date = valid_date * 100 + atoi(privacies[i] + 8) - 1; 
        }
        if (valid_date < today_i){
            p_i[i] = 1;
            len++;
        }else{
            p_i[i] = 0;
        }
    }

    int *ret = (int *)malloc(sizeof(int) * len);
    if (!ret)
        return (0);
    //번호 저장
    int j = 0;
    for (size_t i = 0; i < privacies_len; i++){
        if (p_i[i]){
            ret[j++] = i + 1;
        }
    }
    //파기정보 오름차순 리턴
    return (ret);
}


int main(){
   // "2022.05.19"	["A 6", "B 12", "C 3"]	["2021.05.02 A", "2021.07.01 B", "2022.02.19 C", "2022.02.20 C"]
   // "2020.01.01"	["Z 3", "D 5"]	["2019.01.01 D", "2019.11.15 Z", "2019.08.02 D", "2019.07.01 D", "2018.12.28 Z"]
    const char * today = "2019.12.28";
    const char *terms[1] = {"Z 1"};
    const char *p[1] = {"2019.12.01 Z"};
    int *r = solution(today, terms, 1, p, 1);
    int i = 1;
    while (i--){
        printf ("%d\n", *r);
        r++;
    }

    return (0);
}