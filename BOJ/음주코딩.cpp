#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 수의 개수, 라운드 수
int N, K;

vector<long long> arr(100001);
vector<long long> tree(400004);


long long init_segment_tree(int start, int end, int idx) {
    if (start == end) {
        if (arr[start] == 0) {
            return tree[idx] = arr[start];
        }
        return tree[idx] = arr[start] > 0 ? 1 : -1;
    }

    int mid = (start + end) / 2;
    tree[idx] = init_segment_tree(start, mid, idx * 2) 
                 * init_segment_tree(mid + 1, end, idx * 2 + 1);
    return tree[idx];
}


long long interval_sign(int start, int end, int idx, int left, int right) {
    if (end < left || right < start) {
        return 1;
    }
    if (left <= start && end <= right) {
        return tree[idx];
    }

    int mid = (start + end) / 2;
    return interval_sign(start, mid, idx * 2, left, right) 
                * interval_sign(mid + 1, end, idx * 2 + 1, left, right); 
}

void   update_tree(int start, int end, int idx, int where, long long value) {
    // 현재 노드의 구간에 있지 않을때
    if (start > where || where > end) {
        return ;
    }

    if (start == end) {
        arr[start] = value;
        tree[idx] = value;
        return ;
    }

    int mid = (start + end) / 2;
    update_tree(start, mid, idx * 2, where, value);
    update_tree(mid + 1, end, idx * 2 + 1, where, value);

    tree[idx] = tree[idx * 2] * tree[idx * 2 + 1];
}

void    print_segtree(void) {
    for (int i = 1; i <= 7; i++) {
        // if (tree[i] == 0) break ;

        cout << i << "번째 [" << tree[i] << "]" << '\n';
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    while (cin >> N >> K) {
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }

        init_segment_tree(0, N - 1, 1);

        while (K--) {
            char c;
            long long a, b;
            cin >> c >> a >> b;

            if (c == 'P') {
                if (a > b) {
                    swap(a, b);
                }
                int v;
                v = interval_sign(0, N - 1, 1, a - 1, b - 1);
                if (v == 0) {
                    cout << v;
                } else {
                    cout << ((v > 0) ? '+' : '-');
                }
            } else {
                if (b == 0) {
                    update_tree(0, N - 1, 1, a - 1, b);
                } else {
                    update_tree(0, N - 1, 1, a - 1, b > 0 ? 1 : -1);
                }
            }

            // print_segtree();
        }
        cout << '\n';
    }

    return 0;
}