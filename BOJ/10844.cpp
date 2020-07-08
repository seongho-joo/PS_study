/**
 * https://www.acmicpc.net/problem/10844
 * 쉬운 계단 수
 */
#include <iostream>
using namespace std;

#define fastIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define MOD 1000000000

int cache[101][10] = {1};

int main() {
    fastIO();

    int n;
    cin >> n;

    // 1자리 수
    for (int i = 1; i < 10; i++) cache[1][i] = 1;
    for (int i = 2; i <= n; i++) {
        for (int j = 0; j < 10; j++) {
            switch (j) {
                case 0:  // 0뒤엔 1만 올수있음
                    cache[i][j] = cache[i - 1][1] % MOD;
                    break;
                case 9:  // 9뒤엔 8만 올 수 있음
                    cache[i][j] = cache[i - 1][8] % MOD;
                    break;
                default:
                    cache[i][j] =
                        (cache[i - 1][j - 1] + cache[i - 1][j + 1]) % MOD;
                    break;
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < 10; i++) ans = (ans + cache[n][i]) % MOD;

    cout << ans % MOD;

    return 0;
}