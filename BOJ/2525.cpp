/**
 * https://www.acmicpc.net/problem/2525
 * BOJ2525 오븐 시계
 */
#include <iostream>
using namespace std;

int A, B, C;

int main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

    cin >> A >> B >> C;

    C += B;
    while (C >= 60) {
        C -= 60;
        A = (A + 1 % 24);
        A = (A == 24) ? 0 : A;
    }

    cout << A << ' ' << C;

    return 0;
}