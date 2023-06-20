#include <bits/stdc++.h>

#define REP(i, a, b) for (int i = a; i <= b; i++)

// #include <stdio.h>
// #include <stdbool.h>
// #include <stdlib.h>

// deliveries_len은 배열 deliveries의 길이입니다.
// pickups_len은 배열 pickups의 길이입니다.

int is_zero(int arr[], size_t arr_len){
    size_t i;

    i = 0;
    while (i < arr_len){
        if (arr[i++] != 0)
            return (0);
    }
    return (1);
}

long long get_farest(int arr[], size_t arr_len){
    while (arr_len > 0 && arr[arr_len - 1] == 0){
        arr_len--;    
    }
    return (arr_len);
}

void    dec(int arr[], size_t arr_len, int cap){
    while (arr_len > 0 && cap > 0){
        while (arr[arr_len - 1] > 0 && cap > 0){
            cap--;
            arr[arr_len - 1]--;
        }
        arr_len--;
    }
}

long long solution(int cap, int n, int d[], size_t d_len, int p[], size_t p_len) {
    long long dist;
    
    dist = 0;
    //택배 배달 수거 없을때 까지 반복
    long long len =n;
    while (!is_zero(d, d_len) || !is_zero(p, p_len))
    {
        //가장 멀리 가야하는 위치 확인.
        len = get_farest(d, len) > get_farest(p, len) ? get_farest(d, len) : get_farest(p, len);
        //가장 멀리 까지 가서 오면서 배달
        dec(d, len, cap);
        //가장 멀리 까지 가서 오면서 수거
        dec(p, len, cap);
        dist += len * 2;
    }
    return (dist);
}

int main(){
    //4	5	[1, 0, 3, 1, 2]	[0, 3, 0, 4, 0]
    int cap = 1;
    int n = 5;
    int d[] = {0, 0, 0, 0, 2};
    int p[] = {0, 0, 0, 0, 0};
    size_t d_len = 5;
    size_t p_len = 5;
    printf("%lld\n", solution(cap, n, d, d_len, p, p_len));
    return (0);
}