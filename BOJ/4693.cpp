/**
 * https://www.acmicpc.net/problem/4963
 * BOJ4963 섬의 개수
 */
#include <iostream>
#include <vector>
using namespace std;

int dy[8] = {-1, -1, -1, 1, 1, 1, 0, 0};
int dx[8] = {-1, 0, 1, -1, 0, 1, -1, 1};
vector<vector<int> > map;
vector<vector<bool> > v;
int w, h;
int cnt = 0;

void DFS(int y, int x) {
    for (int i = 0; i < 8; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny > -1 && ny < h && nx > -1 && nx < w && !v[ny][nx] &&
            map[ny][nx]) {
            v[ny][nx] = true;
            DFS(ny, nx);
        }
    }
}

int main() {
    while (cin >> w >> h, w != 0) {
        map.resize(h, vector<int>(w));
        v.resize(h, vector<bool>(w));

        for (int i = 0; i < h; i++)
            for (int j = 0; j < w; j++) cin >> map[i][j];

        for (int y = 0; y < h; y++) {
            for (int x = 0; x < w; x++) {
                if (!v[y][x] && map[y][x]) {
                    v[y][x] = true, cnt += 1;
                    DFS(y, x);
                }
            }
        }
        cout << cnt << '\n';
        cnt = 0;
        map.clear();
        v.clear();
    }
}