#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 수의 개수, 턴 수
int N, Q;

vector<long long> arr(100001);
vector<long long> tree(400004);


long long init_segment_tree(int start, int end, int idx) {
    if (start == end) {
        return tree[idx] = arr[start];
    }

    int mid = (start + end) / 2;
    tree[idx] = init_segment_tree(start, mid, idx * 2) 
                 + init_segment_tree(mid + 1, end, idx * 2 + 1);
    return tree[idx];
}


long long interval_sum(int start, int end, int idx, int left, int right) {
    if (end < left || right < start) {
        return 0;
    }
    if (left <= start && end <= right) {
        return tree[idx];
    }

    int mid = (start + end) / 2;
    return interval_sum(start, mid, idx * 2, left, right) 
                + interval_sum(mid + 1, end, idx * 2 + 1, left, right); 
}

void    update_tree(int start, int end, int idx, int where, long long value) {
    if (start > where || where > end) {
        return ;
    }
    tree[idx] += value;
    if (start == end) {
        arr[start] += value;
        return ;
    }

    int mid = (start + end) / 2;
    update_tree(start, mid, idx * 2, where, value);
    update_tree(mid + 1, end, idx * 2 + 1, where, value);
}

void    print_segtree(void) {
    for (int i = 1; i <= 9; i++) {
        // if (tree[i] == 0) break ;

        cout << i << "번째 [" << tree[i] << "]" << '\n';
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> Q;

    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    init_segment_tree(0, N - 1, 1);

    while (Q--) {
        long long x, y, a, b;
        cin >> x >> y >> a >> b;

        if (x > y) {
            swap(x, y);
        }
        cout << interval_sum(0, N - 1, 1, x - 1, y - 1) << '\n';

        update_tree(0, N - 1, 1, a - 1, b - arr[a - 1]);
        // print_segtree();
    }

    return 0;
}