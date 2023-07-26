#include <string>
#include <vector>

using namespace std;

bool    cmp1(vector<string> a, vector<string> b)
{
    if (a[0] < b[0])
        return true;
    return false;
}

bool    cmp2(vector<string> a, vector<string> b)
{
    if (a[1] < b[1])
        return true;
    return false;
}

int solution(vector<vector<string>> b) {
    //시작 시간 기준으로 sort
    sort(b.begin(), b.end(), cmp1);
    vector<vector<string>> c = b;
    for (auto &x : c)
    {
        x[1][3]++;
        if (x[1][3] == '6')
        {
            x[1][1]++;
            if (x[1][1] - 1 == '9')
            {
                x[1][1] = '0';
                x[1][0]++;
            }
            x[1][3] = '0';
        }
    }
    //종료 시간 기준으로 sort
    sort(c.begin(), c.end(), cmp2);
    int t = 0;
    int m = 0;
    int i = 0;
    int j = 0;
    while (i < b.size())
    {
        t++;
        while (j < i && c[j][1] <= b[i][0])
        {
            j++;
            t--;
        }
        //j 시간이 i 시간 보다 작으면 t--
        //반대 t++
        if (m < t)
            m = t;
        i++;
    }
    return m;
}

#include <iostream>
int main(){

    vector<vector<string>>a ={{"15:00", "17:00"}, {"16:40", "18:20"}, {"14:20", "15:20"}, {"14:10", "19:20"}, {"18:20", "21:20"}};
    int i = solution(a);
    cout << i << endl;
    return 0;
}