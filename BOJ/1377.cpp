/**
 * https://www.acmicpc.net/problem/1377
 * BOJ1377 - 버블 소트
 */
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

#define fastIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
vector<pair<int, int> > arr;

int main() {
    fastIO();
    int N, input;
    cin >> N;

    arr.reserve(N + 1);
    for (int i = 0; i < N; i++) {
        cin >> input;
        arr.push_back(make_pair(input, i));
    }

    sort(arr.begin(), arr.end());

    int res = 0;
    for (int i = 0; i < arr.size(); i++) res = max(res, arr[i].second - i);

    cout << res + 1 << '\n';

    return 0;
}