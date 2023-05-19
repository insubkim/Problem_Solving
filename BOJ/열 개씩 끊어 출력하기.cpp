//#include <bits/stdc++.h>
#include <unistd.h>
#include <stdio.h>

#define REP(i, a, b) for (int i = a; i <= b; i++)

//using namespace std;

int main(){
	char	c[11] = {0,};
	int b = 1;
	while (b){
		b = scanf("%10s", c);
		if (b == 10)
			printf("%s\n", c);
		else
			printf("%s", c);
	}
	return (0);
}