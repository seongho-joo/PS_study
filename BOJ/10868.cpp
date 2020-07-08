/**
 * https://www.acmicpc.net/problem/10868
 * BOJ10868 최솟값(세그먼트 트리)
 */
#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

#define fastIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define INF 1000000001
int N, M, a, b;
vector<int> arr;
vector<int> tree;

int init(int i, int s, int e) {
    if (s == e)
        tree[i] = arr[s];
    else {
        int mid = (s + e) / 2;
        tree[i] = min(init(i * 2 + 1, s, mid), init(i * 2 + 2, mid + 1, e));
    }
    return tree[i];
}

int getMin(int i, int s, int e, int left, int right) {
    if (right < s || left > e)
        return INF;
    else if (left <= s && right >= e)
        return tree[i];
    else {
        int mid = (s + e) / 2;
        return min(getMin(i * 2 + 1, s, mid, left, right),
                   getMin(i * 2 + 2, mid + 1, e, left, right));
    }
}

int main() {
    fastIO();

    cin >> N >> M;
    int h = (int)ceil(log2(N));
    int tree_size = 1 << (h + 1);

    arr.resize(N);
    tree.resize(tree_size);

    for (int i = 0; i < N; i++) cin >> arr[i];

    init(0, 0, N - 1);

    for (int i = 0; i < M; i++) {
        cin >> a >> b;
        cout << getMin(0, 0, N - 1, a - 1, b - 1) << '\n';
    }

    return 0;
}