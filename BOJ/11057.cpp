/**
 * https://www.acmicpc.net/problem/11057
 * BOJ11057 오르막 수
 */
#include <iostream>
#include <vector>
using namespace std;

const int MOD = 10007;
int dp[1001][10];

void init() {
    for (int i = 0; i < 10; i++) dp[1][i] = 1;
    for (int i = 2; i < 1001; i++) {
        for (int j = 0; j < 10; j++) {
            for (int k = 0; k <= j; k++) {
                dp[i][j] += dp[i - 1][k];
                dp[i][j] %= MOD;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int n, ans = 0;
    cin >> n;
    init();

    for (int i = 0; i < 10; i++) ans += dp[n][i];

    cout << ans % MOD << '\n';
}
