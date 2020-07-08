/**
 * https://www.acmicpc.net/problem/2493
 * BOJ2493 탑
 */
#include <iostream>
#include <stack>
using namespace std;
#define fastIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

int main() {
    fastIO();
    int N, inp;
    stack<pair<int, int> > st;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> inp;
        while (!st.empty() && st.top().second < inp) st.pop();
        if (st.empty())
            cout << "0 ";
        else
            cout << st.top().first << " ";
        st.push(make_pair(i + 1, inp));
    }

    return 0;
}