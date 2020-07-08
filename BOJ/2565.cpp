/**
 * https://www.acmicpc.net/problem/2565
 * BOJ2565 전깃줄
 */
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

#define fastIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

struct Line {
    int a, b;
};

bool comp(Line x, Line y) { return x.a < y.a; }
const int INF = 98765431;
vector<Line> arr;
vector<int> ans;
int n;

int main() {
    fastIO();
    cin >> n;

    arr.resize(n);

    for (int i = 0; i < n; i++) cin >> arr[i].a >> arr[i].b;
    sort(arr.begin(), arr.end(), comp);

    ans.push_back(-INF);

    for (int i = 0; i < n; i++) {
        int data = arr[i].b;
        if (ans.back() < data)
            ans.push_back(data);
        else {
            auto idx = lower_bound(ans.begin(), ans.end(), data);
            *idx = data;
        }
    }

    cout << n - (ans.size() - 1);

    return 0;
}