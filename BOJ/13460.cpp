//
//  13460.cpp
//  test
//
//  Created by 주성호 on 2020/08/27.
//  Copyright © 2020 주성호. All rights reserved.
//
//  https://www.acmicpc.net/problem/13460
//  BOJ13460 구슬 탈출 2 : 구현, 그래프 이론, 그래프 탐색, 브루트포스 알고리즘, 너비 우선 탐색

#include <iostream>
#include <queue>
#include <vector>
using namespace std;
typedef pair<int, int>  pii;

struct Bead {
    int ry, rx, by, bx;
    int cnt;
    Bead() : ry(0), rx(0), by(0), bx(0), cnt(0) {}
    Bead(int ry, int rx, int by, int bx, int cnt) : ry(ry), rx(rx), by(by), bx(bx), cnt(cnt) {}
};

vector<string> board;
bool visited[10][10][10][10];

int dy[] = {-1, 1, 0, 0};
int dx[] = {0, 0, -1, 1};
Bead bead;
int N, M, res = -1;

bool isInside(pii p) {
    if(p.first > 0 && p.second > 0 && p.first < N && p.second < M) {
        return true;
    }
    return false;
}

void move(pii& p, int d) {
    while(board[p.first][p.second] == '.' || board[p.first][p.second] == 'R' || board[p.first][p.second] == 'B') {
        p.first += dy[d];
        p.second += dx[d];
    }
    if(board[p.first][p.second] == '#') {
        p.first -= dy[d];
        p.second -= dx[d];
    }
}

void bfs() {
    visited[bead.ry][bead.rx][bead.by][bead.bx] = true;
    queue<Bead> Q;
    Q.push(bead);
    
    while(!Q.empty()) {
        Bead cur = Q.front();
        Q.pop();
        if(cur.cnt > 10) {
            res = -1;
            break;
        } else if(board[cur.ry][cur.rx] == 'O') {
            res = cur.cnt;
            break;
        }
        
        for(int i = 0; i < 4; i++) {
            pii blue, red;
            blue.first = cur.by + dy[i];
            blue.second = cur.bx + dx[i];
            red.first = cur.ry + dy[i];
            red.second = cur.rx + dx[i];
            
            move(red, i);
            move(blue, i);
            
            if(board[blue.first][blue.second] == 'O') continue;
            
            if(blue == red) {
                switch (i) {
                    case 0:
                        cur.ry < cur.by ? blue.first += 1 : red.first += 1;
                        break;
                    case 1:
                        cur.ry < cur.by ? red.first -= 1 : blue.first -= 1;
                        break;
                    case 2:
                        cur.rx < cur.bx ? blue.second += 1 : red.second += 1;
                        break;
                    case 3:
                        cur.rx < cur.bx ? red.second -= 1 : blue.second -= 1;
                        break;
                }
            }
            
            if(!visited[red.first][red.second][blue.first][blue.second]) {
                Q.push(Bead(red.first, red.second, blue.first, blue.second, cur.cnt + 1));
                visited[red.first][red.second][blue.first][blue.second] = true;
            }
        }
    }
}

int main() {
    cin >> N >> M;
    board.resize(N);
    
    for(int i = 0; i < N; i++) {
        cin >> board[i];
        for(int j = 0; j < M; j++) {
            if(board[i][j] == 'B') {
                bead.bx = j;
                bead.by = i;
            } else if(board[i][j] == 'R') {
                bead.ry = i;
                bead.rx = j;
            }
        }
    }
    
    bfs();
    
    cout << res << "\n";
    
    return 0;
}
