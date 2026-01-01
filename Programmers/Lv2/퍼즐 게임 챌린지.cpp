#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long cal(vector<int> diffs, vector<int> times, int level)
{
    long long total_time = 0;
    for (int i = 0; i < diffs.size(); i++)
    {
        if (diffs[i] <= level)
            total_time += times[i];
        else 
        {
            int prev_time = i == 0 ? 0 : times[i - 1]; 
            total_time += (diffs[i] - level) * (times[i] + prev_time) 
                            + times[i];
        }
    }

    return total_time;
}

int solution(vector<int> diffs, vector<int> times, long long limit) {
    int answer = 0;

    // diff <= level 소요시간 times[i]
    // level > diff 소요시간 times[i] + (diff - level)(times[i] + times[i-1])

    // limit > 합 ()

    int left = 1; 
    int right = *max_element(diffs.begin(), diffs.end());

    while (left <= right)
    {
        int mid = (left + right) / 2;

        long long total_time = cal(diffs, times, mid);
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


#include <iostream>
int main()
{
    //[1, 5, 3]	[2, 4, 7]	30
    vector<int> a = {1,5,3};
    vector<int> b = {2,4,7};
    int c = 30;
    cout << solution(a, b, c) << endl;
}