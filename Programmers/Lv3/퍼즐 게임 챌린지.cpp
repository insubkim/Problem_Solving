#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int cal(vector<int> diffs, vector<int> times, int level)
{
    for (int i = 0; i < diffs.size(); i++)
    {
        
    }
}

int solution(vector<int> diffs, vector<int> times, long long limit) {
    int answer = 0;

    // diff <= level 소요시간 times[i]
    // level > diff 소요시간 times[i] + (diff - level)(times[i] + times[i-1])

    // limit > 합 ()

    int left = 1; 
    int right = 100000;

    while (left <= right)
    {
        int mid = (left + right) / 2;

        int total_time = cal(diff, times, mid);
        if (total_time <= limit)
        {
            answer = mid;
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }

    return answer;
}

