/**
 * https://www.acmicpc.net/problem/2495
 * BOJ2495 연속구간
 */
#include <iostream>
#include <string>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    for (int i = 0; i < 3; i++) {
        string num;
        cin >> num;
        int cnt = 0, max = 0;
        for (int i = 0; i < 7; i++) {
            if (num[i] == num[i + 1])
                cnt += 1;
            else {
                max = max < cnt ? cnt : max;
                cnt = 0;
            }
        }
        max = max < cnt ? cnt : max;
        cout << (!max ? 1 : max + 1) << '\n';
    }
    return 0;
}
