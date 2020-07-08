/**
 * https://www.acmicpc.net/problem/10988
 * BOJ10988 팰린드롬인지 확인하기
 */
#include <iostream>
#include <string>
using namespace std;

bool isPalindrome(string word) {
    int len = word.size();
    int j = len - 1;
    for (int i = 0; i < len / 2; i++) {
        if (word[i] != word[j--]) return false;
        if (len % 2 == 1 && i + 2 == j) break;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

    string word;

    cin >> word;
    cout << (isPalindrome(word) ? "1" : "0");

    return 0;
}