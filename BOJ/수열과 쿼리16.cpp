#include <iostream>
#include <tuple>
#include <vector>
#include <algorithm>

#include <cmath>
#include <limits.h>

using namespace std;

int N, M;

struct Node {
    long long _min;
    long long _max;
};

vector<long long> arr(1000001);
vector<Node> tree(4000004);

int init_segment_tree(int start, int end, int idx) {
    /*
        // 일반적인 트리는 노드가 0부터 시작하지만, 세그트리는 자식 노드 가리키기 편하기 위해 1부터 시작 
        // start, end 가 같으면 
        tree[idx] = arr[start]
        return tree[idx];

        // 세그 트리 노드는 자식 트리 좌우의 값의 합
        tree[idx] = init_segment_tree(start, mid, idx * 2) + init_segment_tree(mid + 1, end, idx * 2 + 1)
    */
    if (start == end) {
        tree[idx]._min = start;
        return start;
    }
    
    int mid = (start + end) / 2;
    int l = init_segment_tree(start, mid, idx * 2);
    int r = init_segment_tree(mid + 1, end, idx * 2 + 1);

    tree[idx]._min = arr[l] <= arr[r] ? l : r;
    return tree[idx]._min;
}

void    print_segtree(void) {
    for (int i = 1; ; i++) {
        if (tree[i]._max == 0) break ;

        cout << i << "번째 [" << tree[i]._max << '-' << tree[i]._min << "]" << '\n';
    }
}

int interval_min_max(int start, int end, int idx, int left, int right) {
    /*
        start, end : 시작 인덱스, 마지막 인덱스
        left, right : 구할 합의 구간
        // 구간 밖인 경우
        if left > end || right < start
            return 0
        // 구간 안인 경우
        if left <= start & right >= end
            return tree[idx]
        // 아닌 경우 두 부분으로 나눠서 합을 구함
        // (결치는 경우)
        tree[idx] = interval_sum(start, mid, idx * 2, left, right) + interval_sum(mid + 1, end, idx * 2 + 1, left, right)
    */
    if (left > end || right < start) {
        return -1;
    }
    if (left <= start && end <= right) {
        return tree[idx]._min;
    }
    
    int mid = (start + end) / 2;
    int l = interval_min_max(start, mid, idx * 2, left, right);
    int r = interval_min_max(mid + 1, end, idx * 2 + 1, left, right);

    if (l == -1) {
        return r;
    } else if (r == -1) {
        return l;
    } 
    return arr[l] <= arr[r] ? l : r;
}

void    update_node(int start, int end, int idx, int where, int value) {
    if (start > where || end < where) {
        return ;
    }
    if (start == end) {
        arr[start] = value;
        tree[idx]._min = start;
        return ;
    }

    int mid = (start + end) / 2;
    update_node(start, mid, idx * 2, where, value);
    update_node(mid + 1, end, idx * 2 + 1, where, value);
    tree[idx] = arr[tree[idx * 2]._min] <= arr[tree[idx * 2 + 1]._min] ? tree[idx * 2] : tree[idx * 2 + 1];
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);


    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    // 세그먼트 트리
    // 초기화
    init_segment_tree(0, N - 1, 1);

    // print_segtree();

    cin >> M;
    for (int i = 1; i <= M; i++) {
        long long t, a, b;
        cin >> t >> a >> b;
        if (t == 1) {
            update_node(0, N - 1, 1, a - 1, b);
        } else {
            int v = interval_min_max(0, N - 1, 1, a - 1, b - 1);
            cout << v + 1 << '\n'; 
        }
    }
 

    return 0;
}