/**
 * https://www.acmicpc.net/problem/4153
 * BOJ4153 - 직각삼각형
 */
#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;

#define fastIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

int main() {
    fastIO();
    int side[3];

    while (true) {
        for (int i = 0; i < 3; i++) cin >> side[i];
        if (side[0] == 0 && side[1] == 0 && side[2] == 0) break;

        sort(side, side + 3);

        if ((int)pow(side[2], 2) == (int)pow(side[0], 2) + (int)pow(side[1], 2))
            cout << "right\n";
        else
            cout << "wrong\n";
    }

    return 0;
}