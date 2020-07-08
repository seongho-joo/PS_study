/**
 * https://www.acmicpc.net/problem/2846
 * BOJ2846 오르막길
 */
#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    int Max = 0, diff = 0;
    for (int i = 1; i < n; i++) {
        if (arr[i] > arr[i - 1])
            diff += arr[i] - arr[i - 1];
        else
            diff = 0;
        Max = Max > diff ? Max : diff;
    }
    cout << Max << '\n';
    return 0;
}