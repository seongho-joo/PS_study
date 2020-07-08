/**
 * https://www.acmicpc.net/problem/1747
 * BOJ1747 소수&팰린드롬
 */
#include <iostream>
#include <string>
using namespace std;

const int MAX = 2000000;

bool prime[MAX + 1];

void getPrimeNum() {
    prime[0] = true;
    prime[1] = true;
    for (int i = 2; i <= MAX; i++) {
        if (!prime[i])
            for (int j = i + i; j <= MAX; j += i) prime[j] = true;
    }
}

bool isPalindrome(int n) {
    string str = to_string(n);
    int j = str.size() - 1;
    for (int i = 0; i < str.size() / 2; i++) {
        if (str[i] != str[j--]) return false;
        if (str.size() % 2 == 1 && i + 2 == j) break;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    getPrimeNum();
    int n;
    cin >> n;

    for (int i = n; i <= MAX; i++)
        if (!prime[i] && isPalindrome(i)) {
            cout << i;
            return 0;
        }
}