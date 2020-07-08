/**
 * https://www.acmicpc.net/problem/2562
 * BOJ2562 - 최댓값
 */
#include <iostream>
#include <vector>

using namespace std;

#define fastIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

int main() {
    fastIO();
    vector<int> arr(9);

    int index, MAX = -987654321;

    for (int i = 0; i < 9; i++) {
        cin >> arr[i];
        if (MAX < arr[i]) {
            index = i + 1;
            MAX = arr[i];
        }
    }

    cout << MAX << '\n' << index;

    return 0;
}