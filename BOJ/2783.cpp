/**
 * https://www.acmicpc.net/problem/2783
 * BOJ2783 삼각 김밥
 */
#include <iostream>
using namespace std;

#define fastIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define Gram 1000.0

struct Price {
    int X, Y;  // Y그램 당 X원
    double total;
};

int main() {
    fastIO();
    Price inp, origin;
    int N;  // 편의점 개수
    double MIN = 987654321.0;

    cin >> origin.X >> origin.Y >> N;
    origin.total = (Gram / (double)origin.Y) * (double)origin.X;

    while (N--) {
        cin >> inp.X >> inp.Y;
        inp.total = (Gram / (double)inp.Y) * (double)inp.X;
        MIN = MIN < inp.total ? MIN : inp.total;
    }

    MIN = MIN < origin.total ? MIN : origin.total;

    cout << fixed;
    cout.precision(2);
    cout << MIN;

    return 0;
}