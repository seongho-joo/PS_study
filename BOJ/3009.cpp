/**
 * https://www.acmicpc.net/problem/3009
 * BOJ3009 - 네 번째 점
 */
#include <iostream>
#include <vector>
using namespace std;

#define fastIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

int main() {
    fastIO();

    pair<int, int> point[3];
    vector<int> X(1001), Y(1001);

    int x, y;

    for (int i = 0; i < 3; i++) {
        cin >> x >> y;
        X[x]++;
        Y[y]++;
        point[i] = pair<int, int>(x, y);
    }
    int resX = -1, resY = -1;
    for (int i = 0; i < 1001; i++) {
        if (X[i] == 1) resX = i;
        if (Y[i] == 1) resY = i;
        if (resX != -1 && resY != -1) break;
    }

    cout << resX << ' ' << resY << '\n';

    return 0;
}