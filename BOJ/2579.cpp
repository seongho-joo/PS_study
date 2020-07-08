/**
 * https://www.acmicpc.net/problem/2579
 * BOJ2579 - 계단 오르기
 * DP
 */
#include <iostream>
#include <algorithm>
#include <vector>
#define fastIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

vector<int> stair, dp;

void solve(int N)
{
    dp[0] = stair[0];
    // 한 칸씩 올라갔거나 두 칸 한 번에 올라가는 것중 최대 값을 구함
    dp[1] = max(stair[0] + stair[1], stair[1]);
    dp[2] = max(stair[0] + stair[2], stair[1] + stair[2]);
    /**
     * 마지막 칸은 반드식 밟으려면 
     * N - 3 + N 과 N -2 + N이 있는데
     * 한 칸씩 갈 경우 두 칸까지만 오를 수 있기 때문에 한 칸씩 밟을 경우 N - 3 + N - 1 + N 이 된다.
     */
    for (int i = 3; i < N; i++)
        dp[i] = max(dp[i - 3] + stair[i - 1] + stair[i], dp[i - 2] + stair[i]);
}

int main()
{
    fastIO();
    int N; // 계단 개수
    cin >> N;

    stair.resize(N);
    dp.resize(N + 1, -1);

    for (int i = 0; i < N; i++)
        cin >> stair[i];
    solve(N);
    cout << dp[N - 1] << '\n';

    return 0;
}