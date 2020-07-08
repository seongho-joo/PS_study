/**
 * https://www.acmicpc.net/problem/2447
 * BOJ2447 - 별 찍기 - 10
 */
#include <iostream>
#include <vector>
using namespace std;

vector<vector<char> > map;

void solve(int n, int y, int x) {
    if (n == 1) {
        map[y][x] = '*';
        return;
    }
    if (y == 3) {
        int a = 1;
    }
    int div = n / 3;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (i == 1 && j == 1) continue;
            solve(div, y + (div * i), x + (div * j));
        }
    }
}

void output() {
    for (auto i : map) {
        for (auto j : i) cout << j;
        cout << '\n';
    }
}

int main() {
    int n;
    cin >> n;

    map.resize(n, vector<char>(n, ' '));
    solve(n, 0, 0);
    output();

    return 0;
}