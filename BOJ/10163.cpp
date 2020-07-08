/**
 * https://www.acmicpc.net/problem/10163
 * BOJ10163 색종이
 */
#include <iostream>
#include <vector>
using namespace std;

int paper[101][101];
vector<int> cnt;

int main() {
    int n;
    cin >> n;
    cnt.resize(n, 0);

    for (int i = 0; i < n; i++) {
        int x, y, p, q;
        cin >> x >> y >> p >> q;
        for (int j = y; j < y + q; j++)
            for (int k = x; k < x + p; k++) paper[j][k] = i + 1;
    }

    for (int i = 0; i < 101; i++)
        for (int j = 0; j < 101; j++)
            if (paper[i][j] != 0) cnt[paper[i][j] - 1] += 1;

    for (int i = 0; i < cnt.size(); i++) cout << cnt[i] << '\n';
    return 0;
}