#include <iostream>
#include <string>

using namespace std;

int main(void) {
	int N, M, NLength;
	string out;
	string NToString;

	cin >> N >> M;

	NToString = to_string(N);
	NLength = NToString.length();

	if (NLength * N > M) {
		for (int i = 0; i < M / NLength; i++) {
			out += NToString;
		}

		// NToString[M % NLength] = 0; << something very idiot
		NToString = NToString.substr(0, M % NLength);
	 
		out += NToString;
	} else {
		for (int i = 0; i < N; i++) {
			out += NToString;
		}
	}

	cout << out << endl;
	return 0;
}
