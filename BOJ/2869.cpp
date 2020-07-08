/**
 * https://www.acmicpc.net/problem/2869
 * BOJ2869 - 달팽이는 올라가고 싶다
 */
#include <iostream>
using namespace std;

int main() {
    int a, b, v;  // a - 올라가는 높이, b - 내려가는 높이, v - 최종 높이
    cin >> a >> b >> v;

    int day = (v - b - 1) / (a - b) + 1;
    cout << day;

    return 0;
}