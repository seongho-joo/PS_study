/**
 * https://www.acmicpc.net/problem/11051
 * BOJ11051 - 이항 계수2
 */
#include <iostream>
#include <vector>
using namespace std;

vector<vector<int> > dp;

int dino(int n, int r)
{
    if (r == 0 || r == n)
        return 1;
    if (dp[n][r] != 0)
        return dp[n][r];
    return dp[n][r] = (dino(n - 1, r - 1) + dino(n - 1, r)) % 10007;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);z
    cout.tie(NULL);
    int n, r;
    cin >> n >> r;
    dp.resize(n + 1, vector<int>(n + 1));
    cout << dino(n, r);
}