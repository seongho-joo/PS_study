/**
 * https://www.acmicpc.net/problem/11728
 * BOJ11728 - 배열 합치기
 */
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

#define fastIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

int main() {
    fastIO();
    int size1, size2, input;
    cin >> size1 >> size2;

    vector<int> arr1;
    arr1.reserve(size1 + size2);
    while (size1--) {
        cin >> input;
        arr1.push_back(input);
    }
    while (size2--) {
        cin >> input;
        arr1.push_back(input);
    }

    sort(arr1.begin(), arr1.end());

    for (int i = 0; i < arr1.size(); i++) cout << arr1[i] << ' ';

    return 0;
}
