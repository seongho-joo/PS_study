/**
 * https://www.acmicpc.net/problem/2775
 * BOJ2775 - 부녀회장이 될테야
 */
#include <iostream>
#include <vector>
using namespace std;

#define fastIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

vector<vector<int> > apt;

void solve(int n, int k) {
    // 0층 i호는 i명이 살고있고 각 층 1호는 1명이 살고있음
    for (int i = 0; i < n; i++) apt[0][i] = i + 1;
    for (int i = 1; i <= k; i++) apt[i][0] = 1;
    // (a , b) = (a, i - 1) + (a - 1, i)
    for (int i = 1; i <= k; i++)
        for (int j = 1; j < n; j++) apt[i][j] = apt[i][j - 1] + apt[i - 1][j];

    cout << apt[k][n - 1] << '\n';
}

int main() {
    fastIO();

    int T;
    cin >> T;

    while (T--) {
        int k, n;  // 해당하는 층, 해당하는 호 수
        cin >> k >> n;
        apt.resize(k + 1, vector<int>(n));
        solve(n, k);
        apt.clear();
    }

    return 0;
}