#include <iostream>

using namespace std;

int main() {
    int N;
    int score[1001] = {0,};

    cin >> N;

    int score_max = 0;
    for (int i = 1;i <= N; i++) {
        cin >> score[i];
        if (score_max < score[i]) {
            score_max = score[i];
        }
    }

    double sum = 0;
    for (int i = 1;i <= N; i++) {
        sum += ((double)score[i] / score_max) * 100;
    }
    
    cout << sum / N << endl;
}