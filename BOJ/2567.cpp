/**
 * https://www.acmicpc.net/problem/2567
 * BOJ2567 색종이 - 2
 */
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

const int MAX = 101;
bool paper[MAX][MAX];
int dy[] = {-1, 1, 0, 0};
int dx[] = {0, 0, -1, 1};
int ans = 0;

void DFS(int y, int x) {
    if (!paper[y][x]) {
        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (ny > -1 && nx > -1 && ny < MAX && nx < MAX && paper[ny][nx])
                ans += 1;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int x, y, n;
    cin >> n;
    while (n--) {
        cin >> x >> y;
        for (int i = x; i < x + 10; i++)
            for (int j = y; j < y + 10; j++)
                if (!paper[i][j]) paper[i][j] = true;
    }
    for (int i = 0; i < MAX; i++)
        for (int j = 0; j < MAX; j++) DFS(i, j);
    cout << ans << '\n';
    return 0;
}