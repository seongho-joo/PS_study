/**
 * https://www.acmicpc.net/problem/3052
 * BOJ3052 - 나머지
 */
#include <iostream>
#include <vector>
using namespace std;

#define fastIO() \
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

int main() {
    fastIO();
    vector<int> mod;
    int size = 10, input;
    mod.resize(43, 0);

    while (size--) {
        cin >> input;
        mod[input % 42]++;
    }
    int count = 0;
    for (int i = 0; i < mod.size(); i++)
        if (mod[i] > 0) count++;

    cout << count << '\n';

    return 0;
}