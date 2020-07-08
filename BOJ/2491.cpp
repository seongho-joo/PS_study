/**
 * https://www.acmicpc.net/problem/2491
 * BOJ2491 수열
 */
#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int N, increase = 0, decrease = 0, inMax = 0, deMax = 0;
    vector<int> arr;
    cin >> N;

    arr.resize(N);
    for (int i = 0; i < N; i++) cin >> arr[i];

    for (int i = 1; i < N; i++) {
        if (arr[i] >= arr[i - 1])
            increase += 1;
        else {
            inMax = inMax < increase ? increase : inMax;
            increase = 0;
        }
        inMax = inMax < increase ? increase : inMax;
    }

    for (int i = 1; i < N; i++) {
        if (arr[i] <= arr[i - 1])
            decrease += 1;
        else {
            deMax = deMax < decrease ? decrease : deMax;
            decrease = 0;
        }
        deMax = deMax < decrease ? decrease : deMax;
    }

    cout << (inMax < deMax ? deMax + 1 : inMax + 1);

    return 0;
}