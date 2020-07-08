/**
 * https://www.acmicpc.net/problem/10250
 * BOJ10250 - ACM 호텔
 */
#include <iostream>
using namespace std;

#define fastIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

int h, w, n;  // 층 수, 방 수, n번째 손님

void solve() {
    int cnt = 1;

    while (n > h) {
        cnt++;
        n -= h;
    }
    cout << n * 100 + cnt << '\n';
}

int main() {
    fastIO();

    int t;
    cin >> t;

    while (t--) {
        cin >> h >> w >> n;
        solve();
    }

    return 0;
}