/**
 * https://www.acmicpc.net/problem/2156
 * 포도주 시식
 */
#include <iostream>
#include <vector>
using namespace std;

#define fastIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

vector<int> W;
vector<int> D;

int max(int a, int b, int c) {
    return a > b ? (a > c) ? a : c : (b > c) ? b : c;
}

void solve(int n) {
    D[1] = W[0];
    D[2] = W[0] + W[1];

    /**
     * 안마시는 경우 : D[n-1]
     * 1번째 연속으로 마시는 경우 : D[n-2] + W[n]
     * 2번째 연속으로 마시는 경우 : D[n-3] + W[n-1] + W[n]
     */
    for (int i = 3; i <= n; i++)
        D[i] =
            max(D[i - 1], D[i - 2] + W[i - 1], D[i - 3] + W[i - 2] + W[i - 1]);
    cout << D[n];
}

int main() {
    fastIO();

    int n, input;
    cin >> n;

    W.reserve(n);
    D.resize(n + 1);

    while (n--) {
        cin >> input;
        W.push_back(input);
    }

    solve(W.size());

    return 0;
}