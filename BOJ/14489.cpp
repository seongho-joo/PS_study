/**
 * https://www.acmicpc.net/problem/14489
 * BOJ14489 치킨 두 마리 (...)
 */
#include <iostream>
using namespace std;

#define fastIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

int A, B, C;

int main() {
    fastIO();

    cin >> A >> B;
    cin >> C;

    int total = A + B;

    if (total < C * 2)
        cout << total;
    else
        cout << total - (C * 2);

    return 0;
}