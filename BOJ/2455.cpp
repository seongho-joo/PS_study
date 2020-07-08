/**
 * https://www.acmicpc.net/problem/2455
 * BOJ2455 지능형 기차
 */
#include <iostream>
using namespace std;

#define fastIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

int in, out, total, MAX;

int main() {
    fastIO();

    for(int i = 0; i < 4; i++) {
        cin >> out >> in;
        total = (total - out) + in;
        MAX = MAX < total ? total : MAX;
    }

    cout << MAX;

    return 0;
}