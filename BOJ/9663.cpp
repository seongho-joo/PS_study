/**
 * https://www.acmicpc.net/problem/9663
 * BOJ9663 - N-Queen
 */
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

#define MAX 16
#define fastIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
int N, ans;
/** 퀸이 있는 위치 */
int queen[MAX];

bool promising(int i) {
    for (int j = 1; j < i; j++) {
        /** 같은 행 열 비교 */
        if (queen[i] == queen[j]) return false;
        /** 대각선 비교 */
        if (abs(queen[i] - queen[j]) == abs(i - j)) return false;
    }
    return true;
}

void backTracking(int row) {
    if (row == N)
        ans += 1;
    else {
        for (int i = 1; i < N + 1; i++) {
            queen[row + 1] = i;
            if (promising(row + 1))
                backTracking(row + 1);
            else
                queen[row + 1] = 0;
        }
    }
    queen[row] = 0;
}

int main() {
    fastIO();
    cin >> N;

    backTracking(0);
    cout << ans << '\n';

    return 0;
}
