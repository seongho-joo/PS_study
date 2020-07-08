/**
 * https://www.acmicpc.net/problem/1987
 * BOJ1987 - 알파벳
 */
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

#define fastIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

vector<vector<char> > board;
vector<bool> visited(26);
int r, c;
// 상하좌우
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};
int ans = 1;
// DFS로 이미 방문한 알파벳인지 확인
void solution(int y, int x, int cnt) {
    ans = max(ans, cnt);
    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (ny > -1 && ny < r && nx > -1 && nx < c) {
            int next = board[ny][nx] - 'A';
            if (!visited[next]) {
                visited[next] = true;
                solution(ny, nx, cnt + 1);
                // 백트래킹
                visited[next] = false;
            }
        }
    }
}

int main() {
    fastIO();
    cin >> r >> c;

    board.resize(r, vector<char>(c));

    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++) cin >> board[i][j];

    visited[board[0][0] - 'A'] = true;

    solution(0, 0, 1);

    cout << ans;

    return 0;
}