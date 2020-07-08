/**
 * BOJ2902 - KMP는 왜 KMP일까?
 */
#include <iostream>
#include <string>
using namespace std;

int main() {
    string str, res;
    cin >> str;
    for(auto i : str) {
        if('A' <= i && 'Z' >= i) {
            res += i;
        }
    }
    cout << res;

    return 0;
}