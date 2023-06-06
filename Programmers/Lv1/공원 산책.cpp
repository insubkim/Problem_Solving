#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> p, vector<string> r) {
    vector<int> a;
    size_t x,y = 0;
    for (auto c : p){
        x = c.find('S');
        if (x < 50){
            break;
        }
        y++:
    }
    size_t d,f;
    int h = (int)p.size();
    int w = (int)p[0].size();
    for (auto c : r){
        d = stoi(c.substr(2));
        f = 1;
        if (c[0] == 'N'){
            if (y >= d){
                for (int i = 1; i <= d; i++){
                    if (p[y - i][x] == 'X'){
                        f = 0;
                        break;
                    }
                }
                if (f)
                    y = y - d;
            }
        }else if (c[0] == 'W'){
            if (x >= d){
                for (int i = 1; i <= d; i++){
                    if (p[y][x - i] == 'X'){
                        f = 0;
                        break;
                    }
                }
                if (f)
                    x = x - d;
            }
        }else if (c[0] == 'S'){
            if (y + d < h){
                for (int i = 1; i <= d; i++){
                    if (p[y + i][x] == 'X'){
                        f = 0;
                        break;
                    }
                }
                if (f)
                    y = y + d;
            }
        }else{
            if (x + d < w){
                for (int i = 1; i <= d; i++){
                    if (p[y][x + i] == 'X'){
                        f = 0;
                        break;
                    }
                }
                if (f)
                    x = x + d;
            }
        }
    }
    a.push_back(y);
    a.push_back(x);
    return a;
}


#include <iostream>
int main(){
    string a = "abc";
    cout << a.find('c') << endl;
    return 0;
}