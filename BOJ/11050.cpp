/**
 * https://www.acmicpc.net/problem/11050
 * BOJ11050 - 이항 계수
 */
#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> dp;

int dino(int n, int r)
{
    if (r == 0 || r == n)
        return 1;
    if (dp[n][r] != 0)
        return dp[n][r];
    return dp[n][r] = dino(n - 1, r - 1) + dino(n - 1, r);
}

int main()
{
    int n, r;
    cin >> n >> r;
    dp.resize(n + 1, vector<int>(n + 1));
    cout << dino(n, r);
}