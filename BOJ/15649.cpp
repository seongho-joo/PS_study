/**
 * https://www.acmicpc.net/problem/15649
 * BOJ15649 - N과 M (1)
 */
#include <iostream>
#include <vector>
using namespace std;
#define fastIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

int n, m;
vector<int> arr;
vector<bool> visited;

void backTracking(int cnt) {
    if (m == cnt) {
        for (int i = 0; i < m; i++) cout << arr[i] << ' ';
        cout << '\n';
        return;
    }
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            visited[i] = true;
            arr[cnt] = i;
            backTracking(cnt + 1);
            visited[i] = false;
        }
    }
}

int main() {
    fastIO();

    cin >> n >> m;
    arr.resize(n);
    visited.resize(n + 1, false);

    backTracking(0);

    return 0;
}