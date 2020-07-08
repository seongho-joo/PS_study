/**
 * https://www.acmicpc.net/problem/15651
 * BOJ15651 - N과 M (3)
 */
#include <iostream>
#include <vector>
using namespace std;
#define fastIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

int n, m;
vector<int> arr;

void backTracking(int cnt) {
    if (m == cnt) {
        for (int i = 0; i < m; i++) cout << arr[i] << ' ';
        cout << '\n';
        return;
    }
    for (int i = 1; i <= n; i++) {
        arr[cnt] = i;
        backTracking(cnt + 1);
    }
}

int main() {
    fastIO();

    cin >> n >> m;
    arr.resize(n);

    backTracking(0);

    return 0;
}