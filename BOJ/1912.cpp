/**
 * https://www.acmicpc.net/problem/1912
 * BOJ1912 연속합
 */
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

#define fastIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

vector<int> arr, cache;
int n, Max;

int main() {
    fastIO();
    cin >> n;

    arr.resize(n), cache.resize(n);

    for (int i = 0; i < n; i++) cin >> arr[i];

    cache[0] = Max = arr[0];

    for (int i = 1; i < n; i++) {
        cache[i] = max(cache[i - 1] + arr[i], arr[i]);
        Max = Max < cache[i] ? cache[i] : Max;
    }

    cout << Max;

    return 0;
}