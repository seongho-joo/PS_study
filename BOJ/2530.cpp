/**
 * https://www.acmicpc.net/problem/2530
 * BOJ2530 인공지능 시계
 */
#include <iostream>
using namespace std;

int A, B, C, D;

int main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

    cin >> A >> B >> C >> D;

    C += D;

    while (C > 59) {
        C -= 60;
        B += 1;
        if (B > 59) {
            B -= 60;
            A = (A + 1) % 24;
        }
        A = (A == 24) ? 0 : A;
    }

    cout << A << ' ' << B << ' ' << C;

    return 0;
}