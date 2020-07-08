/**
 * https://www.acmicpc.net/problem/1436
 * BOJ1436 - 영화감독 숌
 */
#include <iostream>
#include <string>
using namespace std;

#define fastIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

int main() {
    fastIO();

    int n, copy, res = 0;
    string str;
    cin >> n;

    for (int i = 666; res != n; i++) {
        copy = i;
        str = to_string(copy);
        // 666이 포함되는지 확인
        if (str.find("666") != string::npos) res++;
    }

    cout << str;

    return 0;
}