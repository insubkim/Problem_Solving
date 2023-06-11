#include <string>
#include <vector>

using namespace std;

int solution(vector<int> n) {
    int a = 45;
    for (int x : n)
        a -= x;
    return a;
}