/**
 * https://www.acmicpc.net/problem/11399
 * BOJ11399 - ATM
 */
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

#define fastIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

int main() {
    fastIO();
    int N;
    cin >> N;

    vector<int> seq;
    seq.reserve(N);

    while (N--) {
        int inp;
        cin >> inp;
        seq.push_back(inp);
    }

    long long ans = 0;
    sort(seq.begin(), seq.end());

    for (int i = 0; i < seq.size(); i++)
        for (int j = 0; j <= i; j++) ans += seq[j];

    cout << ans;

    return 0;
}