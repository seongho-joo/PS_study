/**
 * https://www.acmicpc.net/problem/2556
 * BOJ2556 별 찍기 - 14
 */
#include <iostream>
using namespace std;

int n;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) cout << '*';
        cout << '\n';
    }
    return 0;
}