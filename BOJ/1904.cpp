/**
 * https://www.acmicpc.net/problem/1904
 * BOJ1904 - 01타일
 */
#include <iostream>
#include <vector>
using namespace std;

#define fastIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

vector<int> cache;

int solution(int n) {
    cache.resize(n + 1, -1);
    cache[1] = 1;
    cache[2] = 2;

    for (int i = 3; i <= n; i++)
        cache[i] = (cache[i - 1] + cache[i - 2]) % 15746;

    return cache[n];
}

int main() {
    fastIO();

    int n;
    cin >> n;

    cout << solution(n);

    return 0;
}