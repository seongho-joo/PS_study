/**
 * https://www.acmicpc.net/problem/9095
 * BOJ9095 - 1, 2, 3 더하기
 */
#include <iostream>
#include <vector>
#define fastIO() \
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

vector<int> dp;

int solve(int n) {
    dp[1] = 1;  // 1을 만들 수 있는 경우의 수
    dp[2] = 2;  // 2를 만들 수 있는 경우의 수
    dp[3] = 4;  // 3을 만들 수 있는 경우의 수
    int &ret = dp[n];
    if (ret != 0) return ret;
    return ret = solve(n - 1) + solve(n - 2) + solve(n - 3);
}

int main() {
    fastIO();
    int T;
    cin >> T;

    while (T--) {
        int num;
        cin >> num;
        dp.resize(num + 1);
        cout << solve(num) << '\n';
        dp.clear();
    }

    return 0;
}