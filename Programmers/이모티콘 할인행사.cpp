#include <string>
#include <vector>

#define REP(i,a,b) for(int i = a; i <= b; i++)
#define PB push_back

using namespace std;

typedef vector<int> vi;

vi      v;

int    get_rate(vi& rate, int n){
    if (n == -1)
        return 0;
    if (rate.size() == 0){
        REP(i, 0, n){
            rate.PB(10);
        }
        return 1;
    }
    if (rate[n] != 40){
        rate[n] += 10;
        REP(i, n + 1, (int)rate.size() - 1){
            rate[i] = 10;
        }
        return 1;
    }else{
        return get_rate(rate, n-1);
    }
}

#include <iostream>
vi    solve(vector<vector<int>> users, vector<int> emoticons){
    vi rate;
    int n = 0;
    int m = 0;
    while (get_rate(rate, (int)emoticons.size() - 1)){
        REP(i, 0, (int)emoticons.size() - 1){
            v.PB(emoticons[i] - emoticons[i] * (rate[i] / 100.0));
            cout << rate[i] << endl;
        }
        cout << endl;
        //mm nn 계산
        int sum;
        int nn = 0;
        int mm = 0;
        for (auto x : users){
            sum = 0;
            REP(i, 0, (int)rate.size() - 1){
                if (rate[i] >= x[0]){
                    sum += v[i];
                }
                if (sum >= x[1])
                    break ;
            }
            if (sum >= x[1])
                nn++;
            else
                mm += sum;
        }
        if (nn > n){
            n = nn;
            m = mm;
        }else if (nn == n && mm > m){
            n = nn;
            m = mm;    
        }
        v.clear();
    }
    vector<int> a;
    a.PB(n);
    a.PB(m);
    return a;
}

vector<int> solution(vector<vector<int>> users, vector<int> emoticons) {
    return (solve(users, emoticons));
}

int main(){
    typedef vector<vector<int>> vvi;
    vi v1 = {40, 10000};
    vvi vvi1 = {v1};
    vi e = {7000, 9000};
    vi v3 = solution(vvi1,e);
    for (auto x : v3){
        cout << x << endl;
    }
    return 0;
}