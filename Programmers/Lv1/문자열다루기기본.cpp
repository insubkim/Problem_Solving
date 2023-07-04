#include <string>
#include <vector>

using namespace std;

bool solution(string s) {
    for (auto x : s)
        if (!isdigit(x))
            return false;
    return true;
}