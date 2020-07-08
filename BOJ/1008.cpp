/**
 * https://www.acmicpc.net/problem/1008
 * BOJ1008 - A/B
 */
#include <cstdio>
#include <iostream>
using namespace std;

int main() {
    double a, b;
    cin >> a >> b;
    double res = a / b;

    printf("%.9lf", res);
    return 0;
}