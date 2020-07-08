/**
 * https://www.acmicpc.net/problem/11054
 * 가장 긴 바이토닉 부분 수열
 */
#include <iostream>
#include <vector>
using namespace std;

#define fastIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

vector<int> seq, d, r;

void lis(int n) {
    for (int i = 0; i < n; i++) {
        d[i] = 1;
        for (int j = 0; j < i; j++)
            if (seq[i] > seq[j] && d[j] + 1 > d[i]) d[i] = d[j] + 1;
    }
}

void reverseLis(int n) {
    for (int i = n - 1; i >= 0; i--) {
        r[i] = 1;
        for (int j = n - 1; j >= i; j--)
            if (seq[i] > seq[j] && r[j] + 1 > r[i]) r[i] = r[j] + 1;
    }
}

int solve() {
    int n = seq.size(), res = 0;
    lis(n);
    reverseLis(n);

    for (int i = 0; i < n; i++)
        if (res < d[i] + r[i]) res = d[i] + r[i];

    return res - 1;
}

int main() {
    fastIO();

    int n, inp;
    cin >> n;

    seq.reserve(n);
    d.resize(n + 1);
    r.resize(n + 1);

    while (n--) {
        cin >> inp;
        seq.push_back(inp);
    }

    cout << solve();

    return 0;
}