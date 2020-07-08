/**
 * https://www.acmicpc.net/problem/1085
 * BOJ1085 - 직사각형에서 탈출
 */
#include <cmath>
#include <iostream>
using namespace std;

#define fastIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

int x, y, w, h;

void solve() {
    pair<int, int> res;

    double heightM = h / 2, widthM = w / 2;
    // 너비기준으로 가까운 경계선을 찾음
    if (x > widthM)
        res.first = abs(w - x);
    else
        res.first = x;
    // 높이기준으로 가까운 경계선을 찾음
    if (y > heightM)
        res.second = abs(h - y);
    else
        res.second = y;

    int answer = res.first >= res.second ? res.second : res.first;
    cout << answer;
}

int main() {
    fastIO();

    cin >> x >> y >> w >> h;
    solve();

    return 0;
}