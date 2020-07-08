/**
 * https://www.acmicpc.net/problem/1002
 * BOJ1002 - 터렛
 */
#include <cmath>
#include <iostream>
using namespace std;

#define fastIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

struct Coordinate {
    int x, y, r;
};

// 두 중심의 거리를 구함
double getDistance(Coordinate c[]) {
    return sqrt(pow((c[0].x - c[1].x), 2) + pow((c[0].y - c[1].y), 2));
}

int main() {
    fastIO();
    Coordinate coor[2];

    int T;
    cin >> T;

    while (T--) {
        for (int i = 0; i < 2; i++) cin >> coor[i].x >> coor[i].y >> coor[i].r;

        double distance = getDistance(coor);
        int add = coor[0].r + coor[1].r, sub = abs(coor[1].r - coor[0].r);

        if (sub < distance && add > distance)
            cout << "2\n";
        else if (add == distance || (sub == distance && distance != 0))
            cout << "1\n";
        else if (sub > distance || add < distance)
            cout << "0\n";
        else if (distance == 0) {
            if (coor[0].r == coor[1].r)
                cout << "-1\n";
            else
                cout << "0\n";
        }
    }

    return 0;
}