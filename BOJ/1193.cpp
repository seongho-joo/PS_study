/**
 * https://www.acmicpc.net/problem/1193
 * BOJ1193 - 분수찾기
 */
#include <iostream>
using namespace std;

#define fastIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

int main() {
    fastIO();

    int n;
    cin >> n;

    if (n == 1) cout << "1/1\n";

    int sum = 1, num = 1;
    long long cnt = 0;

    while (true) {
        sum++;
        cnt += num++;
        if (cnt >= n) break;
    }

    int parent, child;
    child = parent = 1;

    if (sum % 2 == 1)
        child = sum - 1;
    else
        parent = sum - 1;

    while (cnt != n) {
        if (sum % 2 == 1) {
            parent++;
            child--;
        } else {
            parent--;
            child++;
        }
        cnt--;
    }

    cout << child << '/' << parent;

    return 0;
}