/**
 * https://www.acmicpc.net/problem/2986
 * BOJ2986 파스칼 : 구현문제
 */

#include <iostream>
using namespace std;

int main() {
    int n, k = 1;
    cin >> n;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            k = n / i;
            break;
        }
    }
    cout << n - k << "\n";
    return 0;
}
