/**
 * https://www.acmicpc.net/problem/2446
 * BOJ2446 별 찍기 - 9
 */
// *********
//  *******
//   *****
//    ***
//     *
//    ***
//   *****
//  *******
// *********
#include <iostream>
using namespace std;

int N;

int main() {
    cin >> N;
    /** Down */
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < i; j++) cout << ' ';
        for (int j = 0; j < 2 * (N - i) - 1; j++) cout << '*';
        cout << '\n';
    }
    /** Up */
    for (int i = 1; i < N; i++) {
        for (int j = 0; j < N - i - 1; j++) cout << ' ';
        for (int j = 0; j < i * 2 + 1; j++) cout << '*';
        cout << '\n';
    }

    return 0;
}