/**
 * https://www.acmicpc.net/problem/1012
 * BOJ1012 유기농 배추
 * DFS
 */
#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;
#define fastIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

vector<vector<int> > land;
vector<vector<bool> > v;

int dy[4] = {1, -1, 0, 0};
int dx[4] = {0, 0, -1, 1};
int T, M, N, K;
int X, Y;

void DFS(int y, int x) {
    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny > -1 && nx > -1 && nx < M && ny < N)
            if (land[ny][nx] == 1 && !v[ny][nx]) {
                v[ny][nx] = true;
                DFS(ny, nx);
            }
    }
}

int main() {
    fastIO();
    cin >> T;
    while (T--) {
        int ans = 0;

        cin >> M >> N >> K;

        land.resize(N, vector<int>(M, 0));
        v.resize(N, vector<bool>(M, false));

        while (K--) {
            cin >> X >> Y;
            land[Y][X] = 1;
        }

        for (int y = 0; y < N; y++)
            for (int x = 0; x < M; x++)
                if (land[y][x] && !v[y][x]) {
                    DFS(y, x);
                    ans += 1;
                }
        cout << ans << '\n';
        land.clear();
        v.clear();
    }
    return 0;
}