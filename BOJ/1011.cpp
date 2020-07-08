/**
 * https://www.acmicpc.net/problem/1011
 * BOJ1011 - Fly me to the Alpha Centauri
 */
#include <cmath>
#include <iostream>
using namespace std;

#define fastIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

int main() {
    fastIO();
    int T;
    unsigned int x, y;
    cin >> T;

    while (T--) {
        cin >> x >> y;
        long long i = 1;

        while (i * i <= (y - x)) i++;

        i--;

        long long distance = (y - x) - (i * i);
        distance = (long long)ceil((double)distance / (double)i);

        cout << 2 * i - 1 + distance << '\n';
    }

    return 0;
}