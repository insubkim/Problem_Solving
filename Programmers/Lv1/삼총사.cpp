#include <string>
#include <vector>

using namespace std;

int solution(vector<int> n) {
    int a = 0;

    for (int i = 0; i < (int)n.size() - 2; i++){
        for (int j = i + 1; j < (int)n.size() - 1; j++){
            for (int k = j + 1; k < (int)n.size(); k++){
                if (n[i] + n[j] + n[k] == 0)
                    a++;
            }
        }
    }
    return a;
}