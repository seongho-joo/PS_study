/**
 * https://www.acmicpc.net/problem/4948
 * BOJ4948 - 베르트랑 공준
 */
#include <iostream>
#include <vector>
using namespace std;

#define fastIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

int solve(int num) {
    vector<bool> pNum(2 * num + 1);
    pNum[0] = true;
    pNum[1] = true;

    for (int i = 2; i <= (2 * num); i++)
        if (!pNum[i])
            for (int j = i + i; j <= (2 * num); j += i) pNum[j] = true;
    int res = 0;
    for (int i = num + 1; i <= 2 * num; i++)
        if (!pNum[i]) res++;

    return res;
}

int main() {
    fastIO();

    int data = -1;
    while (true) {
        cin >> data;
        if (data == 0) break;
        cout << solve(data) << '\n';
    }

    return 0;
}