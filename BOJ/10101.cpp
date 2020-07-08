/**
 * https://www.acmicpc.net/problem/10101
 * BOJ10101 삼각형 외우기
 */
#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int a, b, c;
    cin >> a >> b >> c;

    if (a + b + c != 180)
        cout << "Error" << '\n';
    else {
        if (a == 60 && b == 60) cout << "Equilateral" << '\n';
    }
    return 0;
}
