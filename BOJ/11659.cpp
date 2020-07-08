/**
 * https://www.acmicpc.net/problem/11659
 * BOJ11659 구간 합 구하기 4
 */
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

vector<int> tree, arr;
int N, M;

int init(int idx, int start, int end) {
    if (start == end)
        tree[idx] = arr[start];
    else {
        int mid = (start + end) / 2;
        tree[idx] =
            init(idx * 2 + 1, start, mid) + init(idx * 2 + 2, mid + 1, end);
    }
    return tree[idx];
}

int print(int idx, int start, int end, int left, int right) {
    if (right < start || left > end)
        return 0;
    else if (left <= start && right >= end)
        return tree[idx];
    else {
        int mid = (start + end) / 2;
        return print(idx * 2 + 1, start, mid, left, right) +
               print(idx * 2 + 2, mid + 1, end, left, right);
    }
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    cin >> N >> M;
    int h = (int)ceil(log2(N));
    int size = 1 << (h + 1);

    arr.resize(N);
    tree.resize(size);
    for (int i = 0; i < N; i++) cin >> arr[i];

    init(0, 0, N - 1);
    while (M--) {
        int x, y;
        cin >> x >> y;
        cout << print(0, 0, N - 1, x - 1, y - 1) << '\n';
    }
    return 0;
}
