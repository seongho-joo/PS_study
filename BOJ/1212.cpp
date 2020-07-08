/**
 * https://www.acmicpc.net/problem/1212
 * BOJ1212 8진수 2진수
 */
#include <iostream>
#include <string>
using namespace std;

#define fastIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

string octal, ans;

void octal_to_binary(int n) {
    string temp;
    while (true) {
        if (n == 0) {
            temp += n + 48;
            break;
        } else {
            temp += (n % 2) + 48;
            n /= 2;
        }
    }
    while (temp.size() < 3) temp.push_back('0');
    while (temp.size() > 3) temp.pop_back();

    for (int i = temp.size() - 1; i >= 0; i--) ans += temp[i];
}

int main() {
    fastIO();

    cin >> octal;
    if (octal == "0") {
        cout << 0;
        return 0;
    }

    for (int i = 0; i < octal.size(); i++) octal_to_binary(octal[i] - 48);

    while (ans[0] == '0') ans.erase(ans.begin());

    cout << ans;

    return 0;
}