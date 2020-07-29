//
//  7562.cpp
//  test
//
//  Created by 주성호 on 2020/07/29.
//  Copyright © 2020 주성호. All rights reserved.
//
//  https://www.acmicpc.net/problem/7562
//  BOJ7562 나이트의 이동 : BFS

#include <iostream>
#include <queue>
#include <vector>
using namespace std;
typedef vector<vector<int> > vvi;
typedef vector<vector<bool> > vvb;

struct Night{
    int y, x, cnt;
    Night() : y(-1), x(-1), cnt(0) {}
    Night(int y, int x, int cnt) : y(y), x(x), cnt(cnt) {}
};

int T, I;
int dy[] = {-2, -2, 1, -1, 2, 2, -1, 1};
int dx[] = {-1, 1, 2, 2, -1, 1, -2, -2};
Night s, e;

int bfs(vvi& v) {
    queue<Night> Q;
    Q.push(s);
    vvb visited;
    visited.resize(I, vector<bool>(I, false));
    
    while(!Q.empty()) {
        Night p = Q.front(); Q.pop();
        if(v[p.y][p.x] == 1)
            return p.cnt;
        for(int i = 0; i < 8; i++) {
            int ny = p.y + dy[i];
            int nx = p.x + dx[i];
            if(ny >= 0 && nx >= 0 && ny < I && nx < I && !visited[ny][nx]) {
                visited[ny][nx] = true;
                Q.push({ny, nx, p.cnt + 1});
            }
        }
    }
    
    return 0;
}

int main() {
    cin >> T;
    while(T--) {
        cin >> I;
        vvi board;
        board.resize(I, vector<int>(I, 0));
        cin >> s.y >> s.x >> e.y >> e.x;
        board[e.y][e.x] = 1;
        cout << bfs(board) << "\n";
    }
    return 0;
}
