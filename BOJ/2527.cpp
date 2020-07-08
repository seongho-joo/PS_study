/**
 * https://www.acmicpc.net/problem/2527
 * BOJ2527 직사각형
 */
#include <algorithm>
#include <iostream>
using namespace std;

struct Point {
    int x, y, p, q;
    Point() : x(0), y(0), p(0), q(0) {}
    Point(int x, int y, int p, int q) : x(x), y(y), p(p), q(q) {}
};

char solve(Point a, Point b) {
    int left = max(a.x, b.x);
    int right = min(a.p, b.p);
    int top = min(a.q, b.q);
    int bottom = max(a.y, b.y);

    int width = right - left;
    int height = top - bottom;

    if (width == 0 && height == 0)
        return 'c';
    else if (width == 0 || height == 0)
        return 'b';
    else if (width < 0 || height < 0)
        return 'd';
    else
        return 'a';
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int x, y, p, q;
    for (int i = 0; i < 4; i++) {
        Point a, b;
        cin >> x >> y >> p >> q;
        a = Point(x, y, p, q);
        cin >> x >> y >> p >> q;
        b = Point(x, y, p, q);
        cout << solve(a, b) << '\n';
    }
    return 0;
}
