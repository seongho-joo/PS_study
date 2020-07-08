/**
 * https://www.acmicpc.net/problem/11758
 * BOJ11758 CCW
 */
#include <iostream>
using namespace std;

struct Point {
    int x, y;
    Point() : x(0), y(0) {}
    Point(int x1, int y1) : x(x1), y(y1) {}
};

Point p[3];

int ccw(Point a, Point b, Point c) {
    return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
}

int main() {
    int x, y;

    for (int i = 0; i < 3; i++) {
        cin >> x >> y;
        p[i] = Point(x, y);
    }

    int ans = ccw(p[0], p[1], p[2]);

    if (ans < 0)
        cout << -1;
    else if (ans == 0)
        cout << ans;
    else
        cout << 1;

    return 0;
}