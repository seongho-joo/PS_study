/**
 * https://www.acmicpc.net/problem/2669
 * BOJ2669 직사각형 네개의 합집합의 면적 구하기
 */
#include <iostream>
using namespace std;

#define fastIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
int x, y, dx, dy, ans;
int square[101][101];

void Fill(int n) {
    for (int i = y; i < dy; i++) {
        for (int j = x; j < dx; j++) {
            if (square[i][j] == 0) {
                ans += 1;
                square[i][j] = n;
            }
        }
    }
}

int main() {
    fastIO();

    for (int i = 0; i < 4; i++) {
        cin >> x >> y >> dx >> dy;
        Fill(i + 1);
    }

    cout << ans;

    return 0;
}