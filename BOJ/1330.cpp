/**
 * https://www.acmicpc.net/problem/1330
 * BOJ1330 - 두 수 비교하기
 */
#include <iostream>

using namespace std;

#define fastIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

int main() {
    fastIO();

    int a, b;
    cin >> a >> b;

    if (a > b)
        cout << ">\n";
    else if (a == b)
        cout << "==\n";
    else
        cout << "<\n";

    return 0;
}