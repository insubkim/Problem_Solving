#include <string>
#include <vector>

using namespace std;

long long   next_dummy_tree(long long p_tree){
    long long dummy_tree = 0;
    while (p_tree & 1){
        p_tree = p_tree >> 1;
        dummy_tree = dummy_tree << 2;
        dummy_tree |= 0b10;
    }
    return dummy_tree;
}

long long   next_p_tree(long long p_tree){
    long long new_p_tree = p_tree;
    int n = 0;
    while (p_tree & 1){
        p_tree = p_tree >> 1;
        n++;
    }
    return ((new_p_tree << (n + 1)) | (new_p_tree << 1)) | 1;
}

bool    solve(long long n){
    long long p_tree = 0b1;
    long long dummy_tree;
    while (n >= p_tree){
        if (p_tree == n){
            return true;
        }
        dummy_tree = next_dummy_tree(p_tree);
        p_tree = next_p_tree(p_tree);
        if (dummy_tree == (n & dummy_tree) && n < p_tree)
            return true;
    }
    return false;
}

vector<int> solution(vector<long long> n) {
    vector<int> a;
    for (auto x : n){
        a.push_back(solve(x));
    }
    return a;
}
#include <iostream>
int main(){
    long long k = 0b1010101010101010 | 0b1111111;
    vector<long long>a ={k};
    cout << k << endl;
    vector<int> l = solution(a);
    cout << l[0] << endl;
}
/*

101010
 11111


*/