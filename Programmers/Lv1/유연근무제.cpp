#include <string>
#include <vector>
#include <iostream>

using namespace std;

#define MON 1
#define TUE 2
#define WED 3
#define THU 4
#define FRI 5
#define SAT 6
#define SUN 7

int solution(vector<int> schedules, vector<vector<int>> timelogs, int startday) {
    int answer = schedules.size();

    for (int i = 0; i < schedules.size(); i++)
    {
        int hour = schedules[i] / 100;
        int min = schedules[i] % 100;

        min += 10;
        if (min >= 60)
        {
            min -= 60;
            hour++;
        }

        int deadline = hour * 100 + min;

        for (int j = 0; j < timelogs[i].size(); j++)
        {
            int date = (startday - 1 + j) % 7 + 1;

            if (date == SAT || date == SUN)
                continue;
            
            if (deadline < timelogs[i][j])
            {
                answer--;
                break;
            }
        }
    }

    return answer;
}

int main()
{
    vector<int> schedules = {730, 855, 700, 720};
    vector<vector<int>> timelogs = {{710, 700, 650, 735, 700, 931, 912}, {908, 901, 805, 815, 800, 831, 835}, {705, 701, 702, 705, 710, 710, 711}, {707, 731, 859, 913, 934, 931, 905}};

    cout << solution(schedules, timelogs, 1) << endl;
}