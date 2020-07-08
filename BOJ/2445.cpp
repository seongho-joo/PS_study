/**
 * https://www.acmicpc.net/problem/2445
 * BOJ2445 별 찍기 - 8
 *        *
 **      **
 ***    ***
 ****  ****
 **********
 ****  ****
 ***    ***
 **      **
 *        *
 */
#include <iostream>
using namespace std;

int N;

int main() {
    cin >> N;

    for (int i = 0; i < N * 2 - 1; i++) {
        if (i < N) {
            for (int j = 0; j <= i; j++) cout << '*';
            for (int j = N - 1; j > i; j--) cout << ' ';
            for (int j = N - 1; j > i; j--) cout << ' ';
            for (int j = 0; j <= i; j++) cout << '*';
            cout << '\n';
        } else {
            for (int j = i; j < N * 2 - 1; j++) cout << '*';
            for (int j = i * 2 + 1, k = 0; j > N * 2 + k; j--, k++) cout << ' ';
            for (int j = i * 2 + 1, k = 0; j > N * 2 + k; j--, k++) cout << ' ';
            for (int j = i; j < N * 2 - 1; j++) cout << '*';
            cout << '\n';
        }
    }

    return 0;
}