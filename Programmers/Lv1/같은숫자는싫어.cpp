#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> arr) 
{
    vector<int> a;
    if (arr.size() == 0){
        return a;
    }
    a.push_back(arr[0]);
    for (auto x : arr){
        if (a.back() != x)
            a.push_back(x);
    }
    return a;
}

#include <iostream>
int main(){
    vector<int> a;
    cout << a.back() << endl;
}