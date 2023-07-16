#include <string>
#include <vector>

using namespace std;

int solution(vector<string> b) {
    int o = 0;
    int x = 0;
    for (auto z :  b){
        for (auto y : z){
            if (y == 'O')
                o++;
            else if (y == 'X')
                x++;
        }
    }
    if (!(o == x || o - 1 == x))
        return 0;
    int x_win = 0;
    int o_win = 0;
    for (auto x :  b){//가로
        if (x[0] == 'X' && x[1] == 'X' && x[2] == 'X')
            x_win++;
        else if (x[0] == 'O' && x[1] == 'O' && x[2] == 'O')
            o_win++;
    }
    for (int i = 0; i < 3; i++){//세로
        if (b[0][i] == 'X' && b[1][i] == 'X' && b[2][i] == 'X')        
            x_win++;
        else if (b[0][i] == 'O' && b[1][i] == 'O' && b[2][i] == 'O')        
            o_win++;
    }
    if (b[0][0] == 'X' && b[1][1] == 'X' && b[2][2] == 'X')        
        x_win++;
    else if (b[0][0] == 'O' && b[1][1] == 'O' && b[2][2] == 'O')        
        o_win++;
    if (b[0][2] == 'X' && b[1][1] == 'X' && b[2][0] == 'X')        
        x_win++;
    else if (b[0][2] == 'O' && b[1][1] == 'O' && b[2][0] == 'O')        
        o_win++;
    if ((x_win > 0 && o_win > 0) || x_win > 1 || o_win > 1)
        return 0;
    else if (x_win && o != x)
        return 0;
    else if (o_win && o - 1 != x)
        return 0;
    return 1;
}


/*

o가 x 보다 크거나 같아야함.
    
둘다 이길수는 없음.
    
x가 이겻으면 o,x 갯수는 같음.
o가 이겻으면 o는 x보다 1큼.   
*/