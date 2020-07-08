/**
 * https://www.acmicpc.net/problem/11651
 * BOJ11651 - 좌표 정렬하기 2
 */
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

#define fastIO() ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

struct Coordinate {
    int x, y;
};

vector<Coordinate> coordinate;

bool comp(Coordinate& a, Coordinate& b) {
    if (a.y == b.y) return a.x < b.x;
    return a.y < b.y;
}

int main() {
    fastIO();

    int N;
    cin >> N;

    coordinate.resize(N);

    for (int i = 0; i < N; i++) cin >> coordinate[i].x >> coordinate[i].y;
    sort(coordinate.begin(), coordinate.end(), comp);
    for (auto i : coordinate) cout << i.x << ' ' << i.y << '\n';

    return 0;
}