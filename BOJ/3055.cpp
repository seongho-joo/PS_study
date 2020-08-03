//
//  3055.cpp
//  test
//
//  Created by 주성호 on 2020/08/03.
//  Copyright © 2020 주성호. All rights reserved.
//
//  https://www.acmicpc.net/problem/3055
//  BOJ3055 탈출 : BFS, 시뮬레이션

#include <iostream>
#include <vector>
#include <queue>
using namespace std;
typedef pair<int, int> pii;

struct Point {
    int y, x, cnt;
    Point() : y(0), x(0), cnt(0) {}
    Point(int y, int x, int cnt) : y(y), x(x), cnt(cnt) {}
};

vector<vector<char> > map;
queue<pii> water;
int dy[] = {-1, 1, 0, 0};
int dx[] = {0, 0, -1, 1};
int R, C;
Point s, d;

void flood() {
    int waterSize = (int)water.size();
    for(int l = 0; l < waterSize; l++) {
        pii p = water.front(); water.pop();
        for(int i = 0; i < 4; i++) {
            int ny = dy[i] + p.first;
            int nx = dx[i] + p.second;
            if(ny >= 0 && nx >= 0 && ny < R && nx < C && map[ny][nx] == '.') {
                map[ny][nx] = '*';
                water.push(make_pair(ny, nx));
            }
        }
    }
}

int moleMove() {
    queue<Point> Q;
    Q.push(s);
    
    while(!Q.empty()) {
        flood(); // 고슴도치는 물이 찰 예정인 칸으로 이동못함
        int mole_size = (int)Q.size();
        for(int l = 0; l < mole_size; l++) {
            Point p = Q.front(); Q.pop();
            for(int i = 0; i < 4; i++) {
                int ny = dy[i] + p.y;
                int nx = dx[i] + p.x;
                if(ny == d.y && nx == d.x) return p.cnt + 1;
                if(ny >= 0 && nx >= 0 && ny < R && nx < C && map[ny][nx] == '.') {
                    map[ny][nx] = '-';
                    Q.push({ny, nx, p.cnt + 1});
                }
            }
        }
    }
    return -1;
}

int main() {
    cin >> R >> C;
    map.resize(R,vector<char>(C));
    
    for(int i = 0; i < R; i++) {
        for(int j = 0; j < C; j++) {
            cin >> map[i][j];
            if(map[i][j] == '*') water.push(make_pair(i, j));
            else if(map[i][j] == 'S') s = Point(i, j, 0);
            else if(map[i][j] == 'D') d = Point(i, j, 0);
        }
    }
    int res = moleMove();
    if(res != -1) cout << res << "\n";
    else cout << "KAKTUS\n";
    return 0;
}
