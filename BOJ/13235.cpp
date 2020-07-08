/**
 * https://www.acmicpc.net/problem/13235
 * BOJ13235 팰린드롬
 */
#include <iostream>
#include <string>
using namespace std;

string str;

bool checkPalindrome(int len) {
    if (len == 1)
        return true;
    else if (len % 2 == 1) {
        for (int i = 0, j = len - 1; i < len / 2; i++, j--)
            if (str[i] != str[j]) return false;
    } else {
        for (int i = 0, j = len - 1; i < len / 2; i++, j--)
            if (str[i] != str[j]) return false;
    }
    return true;
}

int main() {
    cin >> str;

    if (checkPalindrome(str.size()))
        cout << "true";
    else
        cout << "false";

    return 0;
}