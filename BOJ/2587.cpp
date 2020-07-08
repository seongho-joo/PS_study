/**
 * https://www.acmicpc.net/problem/2587
 * BOJ2587 대표값2
 */
#include <algorithm>
#include <iostream>
using namespace std;

int arr[5], sum = 0;

int main() {
    for (int i = 0; i < 5; i++) {
        cin >> arr[i];
        sum += arr[i];
    }

    sort(arr, arr + 5);

    cout << sum / 5 << '\n' << arr[2];

    return 0;
}