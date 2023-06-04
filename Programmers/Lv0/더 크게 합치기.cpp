#include <string>
#include <vector>

using namespace std;

int solution(int a, int b) {
    string aa = to_string(a);
    string bb = to_string(b);
    string ab = aa + bb;
    string ba = bb + aa;
    int ab1 = stoi(ab);
    int ba1 = stoi(ba);
    return ab1 > ba1 ? ab1 : ba1;
}

int solution(int a, int b) {
    return max(stoi(to_string(a) +to_string(b)),stoi(to_string(b) + to_string(a)));
}