/**
 * https://www.acmicpc.net/problem/2748
 * BOJ2748 - 피보나치 수 2
 */
#include <iostream>
using namespace std;

#define fastIO() ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

long long cache[91];

long long fibo(int n) {
    long long& ret = cache[n];
    if (n == 0) return 0;
    if (n == 1) return 1;
    if (ret != 0) return ret;

    return ret = fibo(n - 1) + fibo(n - 2);
}

int main() {
    fastIO();

    int n;
    cin >> n;

    cout << fibo(n);

    return 0;
}