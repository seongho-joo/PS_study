/**
 * https://www.acmicpc.net/problem/11726
 * BOJ11726 - 2×n 타일링
 * DP
 */
#include <iostream>
#include <vector>
using namespace std;

vector<int> dp;
int N;

int tiling(int n)
{
    if (n == 1) // 세로로 배치
        return 1;
    if (n == 2) // 가로로 배치
        return 2;

    int &ret = dp[n];
    if (ret != -1)
        return ret;
    return ret = (tiling(n - 1) + tiling(n - 2)) % 10007;
}

int main()
{
    cin >> N;
    dp.resize(N + 1, -1);
    cout << tiling(N);
    return 0;
}