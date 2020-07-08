/**
 * https://www.acmicpc.net/problem/2153
 * BOJ2153 소수 단어
 */
#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<bool> prime;
int p;

void getPrimeNumber() {
    prime[0] = true;
    prime[1] = false;
    for (int i = 2; i < prime.size(); i++)
        if (!prime[i])
            for (int j = i + i; j < prime.size(); j += i) prime[j] = true;
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    string str;
    cin >> str;

    for (int i = 0; i < str.size(); i++) {
        if (str[i] >= 65 && str[i] <= 90)
            p += (int)(str[i] - 38);
        else
            p += (int)(str[i] - 96);
    }

    prime.resize(p + 1);
    getPrimeNumber();
    cout << (!prime[p] ? "It is a prime word." : "It is not a prime word.");
}