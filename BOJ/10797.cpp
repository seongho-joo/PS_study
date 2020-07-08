/**
 * https://www.acmicpc.net/problem/10797
 * BOJ10797 10부제
 */
#include <iostream>
using namespace std;

int main() {
    int day, car, cnt = 0;

    cin >> day;
    for (int i = 0; i < 5; i++) {
        cin >> car;
        if (day == car) cnt += 1;
    }
    cout << cnt << '\n';

    return 0;
}