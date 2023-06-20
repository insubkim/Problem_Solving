#include <iostream>
#include <string>

using namespace std;

int main(void) {
    string str;
    cin >> str;
    for (auto x : str){
		if (x >= 'a')
			cout << (char)toupper(x);
		else
			cout << (char)tolower(x);
	}
	return 0;
}