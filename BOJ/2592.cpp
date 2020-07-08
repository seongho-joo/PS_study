/**
 * https://www.acmicpc.net/problem/2592
 * BOJ2592 대표값
 */
#include <iostream>
using namespace std;

int arr[10], cnt[101], sum = 0;

int main() {
    for (int i = 1; i <= 10; i++) {
        cin >> arr[i];
        sum += arr[i];
        cnt[arr[i] / 10]++;
    }

    int avg = sum / 10, maxI, Max = 0;
    for (int i = 1; i < 100; i++) {
        if (Max < cnt[i + 1]) {
            Max = cnt[i + 1];
            maxI = i + 1;
        }
    }

    cout << avg << " " << maxI * 10;

    return 0;
}