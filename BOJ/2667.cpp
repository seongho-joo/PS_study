/**
 * https://www.acmicpc.net/problem/2667
 * BOJ2667 단지번호붙이기
 */
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int homeConut;
vector<int> cnt;
vector<string> map;
vector<vector<bool> > v;

int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};
int n, home;

void DFS(int y, int x) {
    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny > -1 && nx > -1 && nx < n && ny < n) {
            if (map[ny][nx] == '1' && !v[ny][nx]) {
                v[ny][nx] = true, home += 1;
                DFS(ny, nx);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

    cin >> n;
    map.resize(n);
    v.resize(n + 1, vector<bool>(n + 1, false));

    for (int i = 0; i < n; i++) cin >> map[i];

    for (int y = 0; y < n; y++) {
        for (int x = 0; x < n; x++) {
            if (map[y][x] == '1' && !v[y][x]) {
                map[y][x] = true, home += 1;
                DFS(y, x);
                cnt.push_back(home);
                homeConut += 1;
                home = 0;
            }
        }
    }

    sort(cnt.begin(), cnt.end());
    cout << homeConut << '\n';
    if (cnt.size() != 0)
        for (int i = 0; i < cnt.size(); i++) cout << cnt[i] << '\n';
    else
        cout << 0;
    return 0;
}