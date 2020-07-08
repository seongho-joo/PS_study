/**
 * https://www.acmicpc.net/problem/1712
 * BOJ1712 - 손익분기점
 */
#include <iostream>

using namespace std;

#define fastIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

int main() {
    fastIO();
    int a, b, c;
    cin >> a >> b >> c;

    if (c - b <= 0)
        cout << -1;
    else
        cout << a / (c - b) + 1;

    return 0;
}