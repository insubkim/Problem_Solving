#include <string>
#include <vector>

using namespace std;

string solution(string s) {
	for (int i = 0; i < (int)s.size(); i++){
		if (s[i] == ' ')
			continue ;
		int j = 0;
		for (; i + j < (int)s.size() && s[i + j] != ' '; j++){
			if (j % 2 == 0){
				s[i + j] = toupper(s[i + j]);
			}else{
				s[i + j] = tolower(s[i + j]);
			}
		}
		i += j;
	}
	return s;
}

#include <iostream>

int main(){
	string a = solution("    abc  a   a    Abcdefg kk ");
	cout << a << endl;
}