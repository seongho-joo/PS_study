/**
 * https://www.acmicpc.net/problem/2475
 * BOJ2475 검증수
 */
#include <cmath>
#include <iostream>
using namespace std;

#define fastIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

int main() {
    fastIO();

    int num[5], ans = 0;

    for (int i = 0; i < 5; i++) {
        cin >> num[i];
        num[i] = (int)pow(num[i], 2);
        ans += num[i];
    }

    cout << ans % 10;

    return 0;
}