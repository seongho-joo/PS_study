/**
 * https://www.acmicpc.net/problem/9506
 * BOJ9506 - 약수들의 합
 */
#include <iostream>
#include <vector>
using namespace std;
#define fastIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

vector<int> divisor;

bool solve(int n) {
    int num;
    for (int i = 1; i < n; i++) {
        num = n % i;
        if (num == 0) divisor.push_back(i);
    }
    int sum = 0;
    for (int i = 0; i < divisor.size(); i++) sum += divisor[i];

    if (sum == n)
        return true;
    else
        return false;
}

int main() {
    fastIO();
    while (true) {
        int n;
        cin >> n;
        if (n == -1) break;
        if (solve(n)) {
            cout << n << " = ";
            for (int i = 0; i < divisor.size(); i++) {
                cout << divisor[i];
                if (i != divisor.size() - 1) cout << " + ";
            }
            cout << '\n';
        } else
            cout << n << " is NOT perfect.\n";
        divisor.clear();
    }
    return 0;
}