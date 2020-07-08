/**
 * https://www.acmicpc.net/problem/9020
 * BOJ9020 - 골드바흐의 추측
 */
#include <iostream>
#include <vector>
using namespace std;

#define MAX 10000
#define fastIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

vector<bool> pNum(MAX + 1, false);

void getPrimeNumber() {
    pNum[1] = true;

    for (int i = 2; i <= MAX; i++)
        if (!pNum[i])
            for (int j = i + i; j <= MAX; j += i) pNum[j] = true;
}

void solve(int num) {
    for (int i = num / 2, j = num / 2; j <= num; i--, j++)
        if (!pNum[i] && !pNum[j]) {
            cout << i << ' ' << j << '\n';
            return;
        }
}

int main() {
    fastIO();

    int T;
    cin >> T;

    getPrimeNumber();

    while (T--) {
        int data;
        cin >> data;
        solve(data);
    }

    return 0;
}