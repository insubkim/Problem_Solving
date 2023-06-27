#include <string>
#include <vector>

using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> a(n);
    int i = 0;
    int k;
    for (auto &x : a){
        k = arr1[i] | arr2[i];
        for (int j = n - 1; j >= 0; j--){
            if (k & (1 << j)){
                x.push_back('#');
            }else{
                x.push_back(' ');
            }
        }
        i++;
    }   
    return a;
}

#include <iostream>
int main(){
    vector<int> arr1 = {9, 20, 28, 18, 11};
    vector<int> arr2 = {30, 1, 21, 17, 28};
    
    vector<string> a = solution(5, arr1, arr2);
    for (auto x : a){
        std::cout << x << endl;
    }
}