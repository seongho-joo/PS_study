/**
 * https://www.acmicpc.net/problem/2042
 * BOJ2042 구간 합 구하기(세그먼트 트리)
 */
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

int n, m, k;  // 수 개수, 수의 변경이 일어나는 회수, 구간의 합을 구하는 회수
int a, b, c;
vector<int> arr;
vector<long long> tree;

long long init(int index, int start, int end) {
    if (start == end)
        tree[index] = arr[start];
    else
        tree[index] = init(index * 2 + 1, start, (start + end) / 2) +
                      init(index * 2 + 2, (start + end) / 2 + 1, end);
    return tree[index];
}

void update(int index, int start, int end, long long diff, int node) {
    if ((node < start || node > end)) return;

    tree[index] += diff;

    if (start != end) {
        int mid = (start + end) / 2;
        update(index * 2 + 1, start, mid, diff, node);
        update(index * 2 + 2, mid + 1, end, diff, node);
    }
}

long long sum(int index, int start, int end, int left, int right) {
    if (right < start || end < left)
        return 0;
    else if (start >= left && end <= right)
        return tree[index];
    else {
        int mid = (start + end) / 2;
        return sum(index * 2 + 1, start, mid, left, right) +
               sum(index * 2 + 2, mid + 1, end, left, right);
    }
}

int main() {
    cin >> n >> m >> k;
    int h = (int)ceil(log2(n));
    int tree_size = 1 << (h + 1);  // 2^(h+1)

    arr.resize(n, 0);
    tree.resize(tree_size);

    for (int i = 0; i < n; i++) cin >> arr[i];
    init(0, 0, n - 1);

    for (int i = 0; i < m + k; i++) {
        cin >> a >> b >> c;
        if (a == 1) {  // 인덱스 값 변경
            long long diff = c - arr[b - 1];
            arr[b - 1] = c;
            update(0, 0, n - 1, diff, b - 1);
        } else {  // b ~ c 구간 합 출력
            cout << sum(0, 0, n - 1, b - 1, c - 1) << '\n';
        }
    }
    return 0;
}