/**
 * https://www.acmicpc.net/problem/12738
 * BOJ12738 가장 긴 증가하는 부분 수열 3(lower_bound)
 */
#include <iostream>
#include <vector>
using namespace std;

#define fastIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

vector<int> L;
int N, inp, INF = 1000000001;

int main() {
    fastIO();
    cin >> N;
    L.push_back(-INF);
    for (int i = 0; i < N; i++) {
        cin >> inp;
        if(L.back() < inp) L.push_back(inp);
        else {
            auto idx = lower_bound(L.begin(), L.end(), inp);
            *idx = inp;
        }
    }

    cout << L.size() - 1;

    return 0;
}