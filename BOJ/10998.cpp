/**
 * https://www.acmicpc.net/problem/10998
 * BOJ10998 - A×B
 */
#include <iostream>
using namespace std;

#define fastIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

int main() {
    fastIO();

    int a, b;
    cin >> a >> b;

    cout << a * b;

    return 0;
}