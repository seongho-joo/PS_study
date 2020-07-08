/**
 * https://www.acmicpc.net/problem/11718
 * BOJ11718 - 그대로 출력하기
 */
#include <iostream>
#include <string>
using namespace std;

#define fastIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

int main() {
    fastIO();
    string inp;

    while (true) {
        getline(cin, inp);
        if (inp == "") break;
        cout << inp << '\n';
    }

    return 0;
}