/**
 * https://www.acmicpc.net/problem/9324
 * BOJ9324 진짜 메시지 : 구현
 */
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

string str;
int cnt[26];

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> str;
        bool flag = false;
        for (int i = 0; i < str.size(); i++) {
            cnt[str[i] - 'A'] += 1;
            if (cnt[str[i] - 'A'] % 3 == 0) {
                if (str[i + 1] == str[i]) {
                    i += 1;
                } else {
                    flag = true;
                    break;
                }
            }
        }
        cout << (flag ? "FAKE" : "OK") << "\n";
        fill_n(cnt, 26, 0);
    }

    return 0;
}
