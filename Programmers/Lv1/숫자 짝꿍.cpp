#include <string>
#include <vector>

using namespace std;

string solution(string X, string Y) {
    string a = "";
    int x_arr[10] = {0,};
    int y_arr[10] = {0,};
    for (char c : X){
        x_arr[c - '0']++;
    }
    for (char c : Y){
        y_arr[c - '0']++;
    }
    int m;
    for (int i = 9; i >= 0; i--){
        m = min(x_arr[i], y_arr[i]);
        while (m--)
            a += i + '0';
    }
    if (a.size() == 0)
        return "-1";
    else if (a.size() > 1 && a[0] == '0')
        return "0";
    return a;
}