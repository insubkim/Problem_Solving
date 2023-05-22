#include <bits/stdc++.h>

#define REP(i, a, b) for (int i = a; i <= b; i++)

using namespace std;

int N,M;
int loc[4];

void    get_loc(char *map){
    REP(i, 0, N - 1){
        REP(j, 0, M - 1){
            if (map[i * M  + j] == 'R'){
                loc[0] = i;
                loc[1] = j;
            }
            else if (map[i * M + j] == 'B'){
                loc[2] = i;
                loc[3] = j;
            }
        }
    }
}

typedef vector<int> vi;

int    solve(int ****dp, char **map, int *loc){
    vi v;
    //0 up 1 r 2 d 3 l
    


}

int main(){
    cin >> N >> M;
    char    map[N][M] = {0,};
    REP(i, 0, N - 1){
        cin >> map[i];
    }
    int dp[N][M][N][M] = {0,};
    get_loc((char*)map);
    dp[loc[0]][loc[1]][loc[2]][loc[3]] = 1;
    REP(i, 0, 3){
        cout << loc[i] << endl;
    }
    cout << solve((int****)dp, (char**)map, (int*)loc) << endl;
    return (0);
}