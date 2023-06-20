#include <string>
#include <vector>

using namespace std;

string solution(vector<string> survey, vector<int> choices) {
    string a = "";
    int s;
    char mbti[26] = {0,};
    for (int i = 0; i < (int)survey.size(); i++){
        if (choices[i] < 4){
            //survey[i][0]
            s = 4 - choices[i];
            mbti[survey[i][0] - 'A'] += s;
        }else if (choices[i] > 4){
            //survey[i][1]
            s = choices[i] - 4;
            mbti[survey[i][1] - 'A'] += s;
        }
    }
    if (mbti['R' - 'A'] >= mbti['T' - 'A']){
        a.push_back('R');
    }else{
        a.push_back('T');
    }
    if (mbti['C' - 'A'] >= mbti['F' - 'A']){
        a.push_back('C');
    }else{
        a.push_back('F');
    }
    if (mbti['J' - 'A'] >= mbti['M' - 'A']){
        a.push_back('J');
    }else{
        a.push_back('M');
    }
    if (mbti['A' - 'A'] >= mbti['N' - 'A']){
        a.push_back('A');
    }else{
        a.push_back('N');
    }
    return a;
}