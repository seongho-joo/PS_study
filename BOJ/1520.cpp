/**
 * https://www.acmicpc.net/problem/1520
 * BOJ1520 내리막 길
 */
#include <iostream>
#include <vector>
using namespace std;

vector<vector<int> > map, visit;
int n, m;
int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};

int search(int y, int x) {
    if (y == n - 1 && x == m - 1) return 1;
    if (visit[y][x] == -1) {
        visit[y][x] = 0;
        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (ny < n && nx < m && ny >= 0 && nx >= 0 &&
                map[ny][nx] < map[y][x])
                visit[y][x] += search(ny, nx);
        }
    }
    return visit[y][x];
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    cin >> n >> m;
    map.resize(n, vector<int>(m));
    visit.resize(n, vector<int>(m, -1));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) cin >> map[i][j];

    search(0, 0);
    cout << visit[0][0] << '\n';

    return 0;
}