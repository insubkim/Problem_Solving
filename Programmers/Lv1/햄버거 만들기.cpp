#include <string>
#include <vector>

using namespace std;

int solution(vector<int> v) {
    int a = 0;
    int f = 1;
    for(int i = 0; i < (int)v.size(); i++){
        if (v[i] == 1 && f == 4){
            a++;
            //del 4 element from begin()
            //check begin if begin is 1 then f = 2;
            //else f = 1;
        }else if (v[i] == f){
            f++;
        }else{
            //if v[i] == 1 and f == 2 then f = 2
            //else if v[i] == 1 
        }
    }
    return a;
}

#include <iostream>
int main(){
    vector <int> l = {1,1,2,3,1,2,3,1};
    int k = solution(l);
    cout << k << endl;
    return 0;
}