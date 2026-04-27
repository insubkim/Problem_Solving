#include <iostream>
#include <tuple>
#include <vector>
#include <algorithm>

#include <cmath>

using namespace std;

int N, M, K;

vector<long long> arr(1000001);
vector<long long> tree(4000004);

#define MOD 1000000007

long long init_segment_tree(int start, int end, int idx) {
    /*
        // 일반적인 트리는 노드가 0부터 시작하지만, 세그트리는 자식 노드 가리키기 편하기 위해 1부터 시작 
        // start, end 가 같으면 
        tree[idx] = arr[start]
        return tree[idx];

        // 세그 트리 노드는 자식 트리 좌우의 값의 합
        tree[idx] = init_segment_tree(start, mid, idx * 2) + init_segment_tree(mid + 1, end, idx * 2 + 1)
    */
    if (start == end) {
        return tree[idx] = arr[start];
    }
    
    int mid = (start + end) / 2;
    tree[idx] = (init_segment_tree(start, mid, idx * 2) * init_segment_tree(mid + 1, end, idx * 2 + 1)) % MOD;
    return tree[idx];
}

void    print_segtree(void) {
    for (int i = 1; ; i++) {
        if (tree[i] == 0) break ;

        cout << i << "번째 [" << tree[i] << "]" << '\n';
    }
}

long long interval_mul(int start, int end, int idx, int left, int right) {
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
        tree[idx] = interval_mul(start, mid, idx * 2, left, right) + interval_mul(mid + 1, end, idx * 2 + 1, left, right)
    */
    if (left > end || right < start) {
        return 1;
    }
    if (left <= start && end <= right) {
        return tree[idx];
    }
    
    int mid = (start + end) / 2;
    
    return (interval_mul(start, mid, idx * 2, left, right) * interval_mul(mid + 1, end, idx * 2 + 1, left, right)) % MOD;
}

void    update_node(int start, int end, int idx, int what, long long value) {
    /*
        // 범위에 있으면 det 을 이용해서 바꾸고
        // 범위가 아닐시 무시
        // (마지막 노드일때 예외 처리)
        // 하위 자식 노드들도 반복
    */

    if (start > what || end < what) {
        return ;
    }
    
    if (start == end) {
        tree[idx] = value;
        arr[what] = value;
        return ;
    }

    int mid = (start + end) / 2;
    update_node(start, mid, idx * 2, what, value);
    update_node(mid + 1, end, idx * 2 + 1, what, value);

    tree[idx] = (tree[idx * 2] * tree[idx * 2 + 1]) % MOD;
}

int main(void) {
    cin >> N >> M >> K;

    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    // 세그먼트 트리
    // 초기화
    init_segment_tree(0, N - 1, 1);

    // print_segtree();

    for (int i = 1; i <= M + K; i++) {
        long long a, b, c;
        cin >> a >> b >> c;
        if (a == 2) {
            // 구간 합
            long long sum = interval_mul(0, N - 1, 1, b - 1, c - 1);
            cout << sum << '\n';
        } else {
            //  초기값 수정
            update_node(0, N - 1, 1, b - 1, c);
            // print_segtree();
        }
    }
 

    return 0;
}