/**
 * https://www.acmicpc.net/problem/2588
 * BOJ2588 - 곱셈
 */
#include <iostream>
#include <string>
using namespace std;

#define fastIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

int main() {
    fastIO();

    int a;
    string b;
    cin >> a >> b;

    for (int i = b.size() - 1; i >= 0; i--) cout << a * (b[i] - 48) << '\n';
    cout << a * atoi(b.c_str());

    return 0;
}