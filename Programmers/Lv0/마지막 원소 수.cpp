#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> n) {
    int l = (int)n.size() - 1;
    if (n[l] > n[l - 1])
        n.push_back(n[l] - n[l - 1]);
    else
        n.push_back(n[l] * 2);
    return n;
}