#include <iostream>

using namespace std;

// 게이트 수
int G;
// 비행기 수
int P;

int parent[100001];

void    init_union_find(void) {
    for (int i = 1; i <= G; i++) {
        parent[i] = i;
    }
}

int find(int a) {
    if (parent[a] == a) return a;
    return parent[a] = find(parent[a]);
}

void    unite(int a, int b) {
    int a_parent = find(a);
    int b_parent = find(b);

    if (a_parent == b_parent) return ;

    parent[b_parent] = a_parent;
}


int main(void) {
    cin >> G >> P;

    init_union_find();

    for (int i = 1; i <= P; i++) {
        int docking_gate;
        cin >> docking_gate;

        int d_parent = find(docking_gate);
        // 도킹 실패
        if (d_parent == 0) {
            cout << i - 1 << '\n';
            return 0;
        } 

        // 도킹 성공
        parent[d_parent] = d_parent - 1;
    }

    // 전부 성공
    cout << P << '\n';


    return 0;
}