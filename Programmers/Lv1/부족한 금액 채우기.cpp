using namespace std;

long long solution(int p, int m, int c)
{
    return ((long long)p * (c) * (c + 1) ) / 2 - m > 0 ? ((long long)p * (c) * (c + 1) ) / 2 - m : 0;
}