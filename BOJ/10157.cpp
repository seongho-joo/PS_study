/**
 * https://www.acmicpc.net/problem/10157
 * BOJ10157 자리배정
 */
#include <iostream>
using namespace std;

typedef pair<int, int> pii;

void solve(int num, int n, int m) {
    pii point;
    point = make_pair(1, 0);
    int s = 1, ret = 0;
    while (true) {
        for (int i = 0; i < m; i++) {
            point.second += s;
            ret += 1;
            if (num == ret) {
                cout << point.first << ' ' << point.second;
                return;
            }
        }
        n -= 1;
        for (int i = 0; i < n; i++) {
            point.first += s;
            ret += 1;
            if (num == ret) {
                cout << point.first << ' ' << point.second;
                return;
            }
        }
        m -= 1;
        s *= -1;
    }
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int n, m, inp;
    cin >> n >> m >> inp;

    if (n * m < inp)
        cout << 0 << '\n';
    else
        solve(inp, n, m);

    return 0;
}