/* 다이나믹 프로그래밍 */
#include <iostream>
using namespace std;

int dp[100001];

int main() {
    int N;
    cin >> N;

    dp[1] = 0;

    for (int i = 2; i <= N; i++) {
        dp[i] = dp[i - 1] + 1;
        if (i % 2 == 0)
            dp[i] = dp[i] > dp[i / 2] + 1 ? dp[i / 2] + 1 : dp[i];
        if (i % 3 == 0)
            dp[i] = dp[i] > dp[i / 3] + 1 ? dp[i / 3] + 1 : dp[i];
    }

    cout << dp[N];
   
    return 0;
}