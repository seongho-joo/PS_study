/**
 * https://www.acmicpc.net/problem/10158
 * BOJ10158 개미
 */
#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int w, h, p, q, t;
    cin >> w >> h >> p >> q >> t;

    int dx = (p + t) / w;
    int dy = (q + t) / h;

    if (dx % 2 == 0)
        p = (p + t) % w;
    else
        p = w - (p + t) % w;
    if (dy % 2 == 0)
        q = (q + t) % h;
    else
        q = h - (q + t) % h;

    cout << p << ' ' << q << '\n';

    return 0;
}