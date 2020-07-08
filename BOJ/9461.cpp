/**
 * https://www.acmicpc.net/problem/9461
 * BOJ9461 - 파도반 수열
 */
#include <iostream>
#include <vector>
using namespace std;

#define fastIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

vector<long long> cache;

long long solve(int n) {
    if (n <= 3) return 1;
    long long& ret = cache[n];

    if (ret != -1) return ret;

    return ret = solve(n - 3) + solve(n - 2);
}

int main() {
    fastIO();

    int T, n;
    cin >> T;

    while (T--) {
        cin >> n;
        cache.resize(n + 1, -1);

        cout << solve(n) << '\n';

        cache.clear();
    }

    return 0;
}