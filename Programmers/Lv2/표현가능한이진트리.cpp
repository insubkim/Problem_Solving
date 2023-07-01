#include <string>
#include <vector>

using namespace std;

long long   next_dummy_tree(int height){
    long long dummy_tree = 0;
    for (int i = 1; i <= height; i++){
        dummy_tree = dummy_tree << 2;
        dummy_tree |= 0b10;
    }
    for (int i = 1; i <= height - 1; i++){
        dummy_tree = dummy_tree << 2;
    }
    return dummy_tree;
}

long long   next_p_tree(int height){
    long long p_tree = 0;
    for (int i = 1; i <= height; i++){
        p_tree = p_tree << 2;
        p_tree |= 0b11;
    }
    for (int i = 1; i <= height - 1; i++){
        p_tree = p_tree << 2;
        p_tree |= 0b11;
    }
    return (p_tree << 1) | 1;
}

int solve(long long n){
    int height = 1;
    long long p_tree = 0b1;
    long long dummy_tree;
    while (n >= p_tree){
        if (p_tree == n){
            return true;
        }
        dummy_tree = next_dummy_tree(height);
        p_tree = next_p_tree(height);
        if (dummy_tree == (n & dummy_tree) && n < p_tree)
            return true;
        height++;
    }
    return false;
}


vector<int> solution(vector<long long> numbers) {
    vector<int> answer;
    for (auto x : numbers){
        answer.push_back(solve(x));
    }
    return answer;
}


#include <iostream>
int main(){
    vector<long long> a = {7};
    solution(a);
}