/**
 * https://www.acmicpc.net/problem/2352
 * BOJ2352 반도체 설계
 */
#include <iostream>
#include <vector>
using namespace std;
#define fastIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

const int INF = 40001;
vector<int> ans;
int n, inp;

int main() {
    fastIO();
    cin >> n;

    ans.push_back(-INF);
    while (n--) {
        cin >> inp;
        if (ans.back() < inp)
            ans.push_back(inp);
        else {
            auto idx = lower_bound(ans.begin(), ans.end(), inp);
            *idx = inp;
        }
    }

    cout << ans.size() - 1;

    return 0;
}