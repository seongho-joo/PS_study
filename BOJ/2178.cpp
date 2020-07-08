/**
 * https://www.acmicpc.net/problem/2178
 * BOJ2178 미로 탐색
 */
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
#define fastIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
typedef pair<int, int> pii;

int N, M;
int dy[4] = {0, 1, -1, 0};
int dx[4] = {1, 0, 0, -1};
vector<vector<char> > maze;
vector<vector<int> > cnt;
vector<vector<bool> > v;

void BFS() {
    queue<pii> q;
    q.push(make_pair(0, 0));
    cnt[0][0] = 1;

    while (!q.empty()) {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (ny > -1 && nx > -1 && ny < N && nx < M) {
                if (maze[ny][nx] == '1' && !v[ny][nx]) {
                    cnt[ny][nx] = cnt[y][x] + 1;
                    v[ny][nx] = true;
                    q.push(make_pair(ny, nx));
                }
            }
        }
    }
}

int main() {
    fastIO();
    cin >> N >> M;
    maze.resize(N, vector<char>(M));
    v.resize(N, vector<bool>(M, false));
    cnt.resize(N, vector<int>(M, 0));

    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++) cin >> maze[i][j];

    BFS();

    cout << cnt[N - 1][M - 1];

    return 0;
}