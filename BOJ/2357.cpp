/**
 * https://www.acmicpc.net/problem/2357
 * BOJ2357 최솟값과 최댓값(세그먼트 트리)
 */
#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

#define fastIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define INF 1000000001

struct Value {
    int max, min;
};

vector<Value> tree;
vector<int> arr;
int N, M, l, r;

int min_Init(int index, int start, int end) {
    if (start == end)
        tree[index].min = arr[start];
    else {
        int mid = (start + end) / 2;
        tree[index].min = min(min_Init(index * 2 + 1, start, mid),
                              min_Init(index * 2 + 2, mid + 1, end));
    }
    return tree[index].min;
}

int max_Init(int index, int start, int end) {
    if (start == end)
        tree[index].max = arr[start];
    else {
        int mid = (start + end) / 2;
        tree[index].max = max(max_Init(index * 2 + 1, start, mid),
                              max_Init(index * 2 + 2, mid + 1, end));
    }
    return tree[index].max;
}

int min_query(int index, int start, int end) {
    if (r < start || l > end)
        return INF;
    else if (l <= start && end <= r)
        return tree[index].min;
    else {
        int mid = (start + end) / 2;
        return min(min_query(index * 2 + 1, start, mid),
                   min_query(index * 2 + 2, mid + 1, end));
    }
}

int max_query(int index, int start, int end) {
    if (r < start || l > end)
        return -1;
    else if (l <= start && end <= r)
        return tree[index].max;
    else {
        int mid = (start + end) / 2;
        return max(max_query(index * 2 + 1, start, mid),
                   max_query(index * 2 + 2, mid + 1, end));
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

    min_Init(0, 0, N - 1), max_Init(0, 0, N - 1);

    for (int i = 0; i < M; i++) {
        cin >> l >> r;
        l -= 1, r -= 1;
        cout << min_query(0, 0, N - 1) << ' ' << max_query(0, 0, N - 1) << '\n';
    }

    return 0;
}