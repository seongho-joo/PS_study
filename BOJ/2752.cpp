/**
 * https://www.acmicpc.net/problem/2752
 * BOJ2752 세수정렬
 */
#include <algorithm>
#include <iostream>
using namespace std;

int arr[3];

int main() {
    for (int i = 0; i < 3; i++) cin >> arr[i];
    sort(arr, arr + 3);

    for (int i = 0; i < 3; i++) cout << arr[i] << ' ';

    return 0;
}