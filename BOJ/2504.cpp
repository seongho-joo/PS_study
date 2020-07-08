/**
 * https://www.acmicpc.net/problem/2504
 * BOJ2504 괄호의 값
 */
#include <iostream>
#include <stack>
#include <string>
#include <vector>
using namespace std;

stack<char> st;
string inp;

int main() {
    cin >> inp;
    bool chk = false;
    int res = 0, mul = 1;
    for (int i = 0; i < inp.length(); i++) {
        if (inp[i] == '(') {
            mul *= 2;
            st.push('(');
            if (i + 1 < inp.length() && inp[i + 1] == ')') res += mul;
        } else if (inp[i] == '[') {
            mul *= 3;
            st.push('[');
            if (i + 1 < inp.length() && inp[i + 1] == ']') res += mul;
        } else if (inp[i] == ')') {
            mul /= 2;
            if (st.empty()) {
                chk = true;
                break;
            }
            if (st.top() == '(') st.pop();

        } else if (inp[i] == ']') {
            mul /= 3;
            if (st.empty()) {
                chk = true;
                break;
            }
            if (st.top() == '[') st.pop();
        }
    }
    if (st.empty() && !chk)
        cout << res;
    else
        cout << 0;
    return 0;
}