#include <string>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;


//살패율 
//스테이지에 있는 사람 수 / 스테이지에 있는 사람 + 스테이지 꺤 사람
//N+1은  n스테이지 깬 사람임.
//스테이지에 도달한 사람 없으면 실패율은 제로
//실패율이 같으면 스태이지  번호 작은 순으로 반환

bool    cmp(int a, int b){
    if (a > b){
        return true;
    }
    return false;
}

bool    cmp2(tuple<int, int, int>a, tuple<int, int, int>b){
    double aa = get<1>(a) / (double)get<2>(a);
    if (get<2>(a) == 0)
        aa = 0;
    double bb = get<1>(b) / (double)get<2>(b);
    if (get<2>(b) == 0)
        bb = 0;
    if (aa > bb){
        return true;
    }else if (aa < bb){
        return false;
    }else if (get<0>(a) < get<0>(b)){
        return true;
    }
    return  false;
}

vector<int> solution(int N, vector<int> s) {
    //내림 차순으로 s 정렬
    sort(s.begin(), s.end(), cmp);
    int reached = 0;
    vector<tuple<int, int, int>> nums(N);
    int i = 0;
    while (i < (int)s.size()){
        if (s[i] == N + 1){
            reached++;
            i++;
        }else
            break ;
    }
    int cur = N;
    for (tuple<int, int, int> &stage : nums){
        get<0>(stage) = cur;
        get<1>(stage) = 0;
        while (i < (int)s.size()){
            if (s[i] == cur){
                get<1>(stage)++;
                i++;
            }else{
                break ;
            }
        }
        reached = reached + get<1>(stage);
        get<2>(stage) = reached;
        cur--;
    }
    sort(nums.begin(), nums.end(), cmp2);
    vector<int> a;
    for (auto x : nums){
        a.push_back(get<0>(x));
    }
    return a;
}