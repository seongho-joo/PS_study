/**
 * https://www.acmicpc.net/problem/11722
 * BOJ11722 가장 긴 감소하는 부분 수열
 */
#include <iostream>
#include <vector>
using namespace std;

#define fastIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

vector<int> cache, arr;
int N, Max = -987654321;

int main() {
    fastIO();
    cin >> N;
    cache.resize(N), arr.resize(N);

    for (int i = 0; i < N; i++) cin >> arr[i];

    cache[0] = 1;

    for (int i = 0; i < N; i++) {
        cache[i] = 1;
        for (int j = 0; j < i; j++) {
            if (arr[i] < arr[j] && cache[j] + 1 > cache[i])
                cache[i] = cache[j] + 1;
        }
        Max = cache[i] < Max ? Max : cache[i];
    }

    cout << Max;

    return 0;
}