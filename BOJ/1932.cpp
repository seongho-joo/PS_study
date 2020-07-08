/**
 * https://www.acmicpc.net/problem/1932
 * BOJ1932 - 정수 삼각형
 * DP
 */
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#define fastIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

vector<vector<int>> triangle;
int dp[501][501];

int solve(int y, int x)
{
    if (y == triangle.size() - 1)
        return triangle[y][x];
    int &ret = dp[y][x];
    if (ret != -1)
        return ret;
    return ret = max(solve(y + 1, x), solve(y + 1, x + 1)) + triangle[y][x];
}

int main()
{
    fastIO();

    int N;
    cin >> N;

    triangle.resize(N);
    memset(dp, -1, sizeof(dp));
    for (int i = 0; i < N; i++)
        for (int j = 0; j <= i; j++)
        {
            int input;
            cin >> input;
            triangle[i].push_back(input);
        }
    cout << solve(0, 0);
    return 0;
}