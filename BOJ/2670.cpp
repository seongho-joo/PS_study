/**
 * https://www.acmicpc.net/problem/2670
 * BOJ2670 연속부분최대곱
 */
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

vector<double> arr;
int MAX;
int n;

int main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    cin >> n;
    arr.resize(n);

    for (int i = 0; i < n; i++) cin >> arr[i];

    double ans = -1;
    for (int i = 0; i < n; i++) {
        double cand = 1;
        for (int j = i; j < n; j++) {
            cand *= arr[j];
            ans = ans > cand ? ans : cand;
        }
    }
    cout.setf(ios::fixed);
    cout.precision(3);
    cout << ans;
}