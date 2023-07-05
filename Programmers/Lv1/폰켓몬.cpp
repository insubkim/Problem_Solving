#include <vector>
#include <set>

using namespace std;

int solution(vector<int> nums)
{
    set<int> a(nums.begin(), nums.end());
    return a.size() > nums.size() / 2 ? nums.size() / 2 : a.size();
}