#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

int* solution(const char* today, const char* terms[], size_t terms_len, const char* privacies[], size_t privacies_len) {
    int today_i = atoi(today);
    today_i = today_i * 100 + atoi(today + 5);
    today_i = today_i * 100 + atoi(today + 8);
    int p_i[privacies_len];
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
        while (atoi(privacies[i] + 5) + mon > 12){
            valid_date++;
            mon -= 12;
        }
        //if (atoi(privacies[i] + 5) + mon > 12){
            //valid_date = valid_date + (atoi(privacies[i] + 5) + mon) / 12;
            //valid_date = valid_date * 100 + (atoi(privacies[i] + 5) + mon) % 12; 
        //}else{
            valid_date = valid_date * 100 + atoi(privacies[i] + 5) + mon;
        //}
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
    const char *terms[1] = {"Z 24"};
    const char *p[1] = {"2019.1.01 Z"};
    int *r = solution(today, terms, 1, p, 1);
    int i = 1;
    while (i--){
        printf ("%d\n", *r);
        r++;
    }

    return (0);
}