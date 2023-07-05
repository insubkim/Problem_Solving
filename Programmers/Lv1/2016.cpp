#include <string>
#include <vector>

using namespace std;

string solution(int a, int b) {
    int i = 4;
    for (int j = 1; j < a; j++){
        if (j == 1 || j == 3 || j == 5 || j == 7 || j == 8 || j == 10)
            i += 31;
        else if (j == 2)
            i += 29;
        else
            i += 30;
    }
    i = (i + b) % 7;
    switch (i)
    {
    case 0:
        return "SUN";
    case 1:
        return "MON";
    case 2:
        return "TUE";
    case 3:
        return "WED";
    case 4:
        return "THU";
    case 5:
        return "FRI";
    default:
        return "SAT";
    }
}

#include <iostream>
int main(){
    cout << solution(9,29) << endl;
}