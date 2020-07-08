/**
 * https://www.acmicpc.net/problem/2563
 * BOJ2563 색종이
 */
#include <iostream>
using namespace std;

#define fastIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

int N;
int x, y, cnt;
int paper[101][101];

void Fill(int n) {
    for (int i = y; i < y + 10; i++) {
        for (int j = x; j < x + 10; j++) {
            if (paper[i][j] == 0)
                paper[i][j] = n;
            else
                cnt += 1;
        }
    }
}

int main() {
    fastIO();
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> x >> y;
        Fill(i + 1);
    }
    cout << (N * 100) - cnt;

    return 0;
}