#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(int a, int b){
    return a > b;
}

int solution(vector<int> cards) {
    vector<int> nums(cards.size(), 1);
    vector<bool> check(cards.size(), true);
    int dept, x;
    vector<int> depts;
    int a, b;
    for (size_t i = 0; i < cards.size(); i++){
        if (!check[i])
            continue ;
        check[i] = false;
        dept = 1;
        x = cards[i] - 1;
        while (check[x]){
            check[x] = false;
            nums[x] = ++dept;
            x = cards[x] - 1;
        }
        depts.push_back(dept);
    }
    sort(depts.begin(), depts.end(), cmp);
    if (depts.size() > 1)
        return depts[0] * depts[1];
    return 0;
}