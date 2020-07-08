/**
 * BOJ1149 - RGB거리 구하기
 * 분류 - DP
 */
#include <iostream>
#include <vector>
#include <algorithm>
#define fastIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main () {
    fastIO();
    int N; // 집의 수
    cin >> N;

    // int v[1001][1001];
    // int dp[1001][1001];

    vector<vector<int> > v;
    vector<vector<int> > dp;
    v.resize(N, vector<int>(3));
    dp.resize(N, vector<int>(3));

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < 3; j++) {
            int data;
            cin >> data;
            v[i][j] = data;
        }
    }

    dp[0][0] = v[0][0];
    dp[0][1] = v[0][1];
    dp[0][2] = v[0][2];

    for(int i = 1; i < N; i++) {
        dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + v[i][0]; // Red
        dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + v[i][1]; // Green
        dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + v[i][2]; // Blue
    }

    int MIN = min(dp[N - 1][0], dp[N - 1][1]);
    cout << min(MIN, dp[N - 1][2]);

    return 0;
}