/**
 * https://www.acmicpc.net/problem/10818
 * BOJ10818 - 최소, 최대
 */
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

#define fastIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

int main() {
    fastIO();
    int n, inp;
    cin >> n;

    vector<int> arr;
    arr.reserve(n);

    while (n--) {
        cin >> inp;
        arr.push_back(inp);
    }

    int MAX = *max_element(arr.begin(), arr.end()),
        MIN = *min_element(arr.begin(), arr.end());

    cout << MIN << ' ' << MAX;

    return 0;
}