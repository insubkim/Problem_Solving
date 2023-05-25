#include <string>
#include <vector>
#include <utility>

using namespace std;

string solution(vector<int> numbers, string hand) {
    string a;
    pair<int, int> l;
    l.first = 4;
    l.second = 1;
    pair<int, int> r;
    r.first = 4;
    r.second = 3;
    int a1,a2,tmp1,tmp2;
    for (auto x : numbers){
        if (x == 1 || x == 4 || x == 7){
            a.push_back('L');
            l.first = x / 3 + 1;
            l.second = 1;
        }else if (x == 3 || x == 6 || x == 9){
            a.push_back('R');
            r.first = x / 3;
            r.second = 3;
        }else if (x == 0){
            a1 = 4;
            a2 = 2;
            tmp1 = abs(a1 - l.first) + abs(a2 - l.second);
            tmp2 = abs(a1 - r.first) + abs(a2 - r.second);
            if (tmp1 == tmp2){
                if (hand == "left"){
                    a.push_back('L');
                    l.first = a1;
                    l.second = a2;
                }else{
                    a.push_back('R');
                    r.first = a1;
                    r.second = a2;
                }
            }else if (tmp1 < tmp2){
                a.push_back('L');
                l.first = a1;
                l.second = a2;                        
            }else{
                a.push_back('R');
                r.first = a1;
                r.second = a2;
            }  
        }else{
            a1 = x / 3  + 1;
            a2 = 2;
            tmp1 = abs(a1 - l.first) + abs(a2 - l.second);
            tmp2 = abs(a1 - r.first) + abs(a2 - r.second);
            if (tmp1 == tmp2){
                if (hand == "left"){
                    a.push_back('L');
                    l.first = a1;
                    l.second = a2;
                }else{
                    a.push_back('R');
                    r.first = a1;
                    r.second = a2;
                }
            }else if (tmp1 < tmp2){
                a.push_back('L');
                l.first = a1;
                l.second = a2;                        
            }else{
                a.push_back('R');
                r.first = a1;
                r.second = a2;
            }
        }
    }

    return a;
}


#include <iostream>

int main(){
    vector<int> k = {1, 3, 4, 5, 8, 2, 1, 4, 5, 9, 5};
    string  c = "right";
    string a  = solution(k, c);
    std::cout<<a<<"\n";
    return 1;
}