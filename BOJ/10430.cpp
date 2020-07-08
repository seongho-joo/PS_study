/**
 * https://www.acmicpc.net/problem/10430
 * BOJ10430 - 나머지
 */
#include <iostream>
using namespace std;

#define fastIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

int main() {
    fastIO();

    int a, b, c;
    cin >> a >> b >> c;

    int mod1 = (a + b) % c, mod2 = (a * b) % c;

    cout << (a + b) % c << '\n';
    cout << (a % c + b % c) % c << '\n';
    cout << (a * b) % c << '\n';
    cout << (a % c * b % c) % c << '\n';

    return 0;
}