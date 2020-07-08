/**
 * https://www.acmicpc.net/problem/2884
 * BOJ2884 - 알람 시계
 */
#include <iostream>
using namespace std;

#define fastIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

int main() {
    fastIO();

    int h, m;
    cin >> h >> m;

    if (m < 45) {
        if (h == 0) h = 24;
        cout << h - 1 << ' ' << m + 15;
    } else
        cout << h << ' ' << m - 45;

    return 0;
}
