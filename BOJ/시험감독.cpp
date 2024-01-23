#include <iostream>
#include <vector>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/ip.h> 
using namespace std;

int main() {
  sockaddr_in a;

  a.sin_family = AF_INET;
  a.sin_addr.s_addr = htonl(INADDR_LOOPBACK);
  a.sin_port = htons(atoi("1"));
  int N, B, C;
  cin >> N;
  vector<int> A(N);
  for (int i = 0; i < N; i++) cin >> A[i];
  cin >> B >> C;
  int num = 0;
  for (int i = 0; i < N; i++) {
    num++;
    A[i] -= B;
    if (A[i] > 0) {
      num += A[i] / C;
      num += A[i] % C == 0 ? 0 : 1;
    }
  }
  cout << num << endl;
  return 0;
}