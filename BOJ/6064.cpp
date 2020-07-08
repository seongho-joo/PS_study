/**
 * https://www.acmicpc.net/problem/6064
 * BOJ6064 - 카잉 달력
 */
#include <iostream>
using namespace std;

#define fastIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

int M, N, x, y;

int GCD(int a, int b) {
    if (a % b == 0) return b;
    return GCD(b, a % b);
}

int LCM(int a, int b) { return a * b / GCD(a, b); }

int solve() {
    // 마지막 해, 처음 x, y 초기화
    int MAX = LCM(M, N), year = x % (M + 1), tempY = x;

    while (true) {
        int ty = tempY % N == 0 ? N : tempY % N;
        if (ty == y) break;

        tempY = ty + M;
        year += M;

        if (year > MAX) return -1;
    }

    return year;
}

int main() {
    fastIO();

    int T;
    cin >> T;

    while (T--) {
        cin >> M >> N >> x >> y;
        cout << solve() << '\n';
    }

    return 0;
}