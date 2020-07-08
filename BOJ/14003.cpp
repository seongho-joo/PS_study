/**
 * https://www.acmicpc.net/problem/14003
 * BOJ14003 가장 긴 증가하는 부분 수열 5
 * LIS 길이와 원소들 출력
 * 이분 탐색이용
 */
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

#define fastIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
int n;
vector<int> arr, parent, ans;

void lis() {
    for (int i = 1; i < n; i++) {
        if (ans.back() < arr[i]) {
            parent[i] = ans.size();
            ans.push_back(arr[i]);
        } else {
            int idx = lower_bound(ans.begin(), ans.end(), arr[i]) - ans.begin();
            ans[idx] = arr[i];
            parent[i] = idx;
        }
    }

    cout << ans.size() << '\n';

    int last = ans.size() - 1;

    stack<int> st;

    for (int i = parent.size() - 1; i >= 0; i--) {
        if (parent[i] == last) {
            st.push(i);
            last -= 1;
        }
    }

    while (!st.empty()) {
        cout << arr[st.top()] << ' ';
        st.pop();
    }
}

int main() {
    fastIO();
    cin >> n;

    arr.resize(n), parent.resize(n);

    for (int i = 0; i < n; i++) cin >> arr[i];
    ans.push_back(arr[0]);
    parent[0] = 0;

    lis();

    return 0;
}