//
//  14503.cpp
//  test
//
//  Created by 주성호 on 2020/07/28.
//  Copyright © 2020 주성호. All rights reserved.
//
//  https://www.acmicpc.net/problem/14503
//  BOJ14503 로봇 청소기 : 시뮬레이션, 구현

#include <iostream>
#include <queue>
#include <vector>
using namespace std;
typedef pair<int, int> pii;

vector<vector<int> > map;
int N, M;
int direction, r, c;
// 0(북), 1(동), 2(남), 3(서)
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};
int back_dy[] = {1, 0, -1, 0};
int back_dx[] = {0, -1, 0, 1};

int solve() {
    int cnt = 1;
    queue<pii> Q;
    Q.push(make_pair(r, c));
    map[r][c] = 2;
    while(!Q.empty()) {
        int wall = 0;
        pii p = Q.front(); Q.pop();
        for(int i = 0; i < 4; i++) {
            // 0 -> 3, 1 -> 0, 2 -> 1, 3 -> 2
            int next_dicetion = direction - 1 < 0 ? 3 : direction - 1;
            int ny = p.first + dy[next_dicetion];
            int nx = p.second + dx[next_dicetion];
            if(ny >= 0 && nx >= 0 && ny < N && nx < M && map[ny][nx] == 0) {
                cnt += 1;
                map[ny][nx] = 2;
                direction = next_dicetion;
                Q.push(make_pair(ny, nx));
                break;
            } else {
                direction = next_dicetion;
                wall += 1;
            }
        }
        // 네 방향 모두 벽 이거나 청소를 한 구역일 경우 후진
        if(wall == 4) {
            int ny = p.first + back_dy[direction];
            int nx = p.second + back_dx[direction];
            // 후진 방향이 벽이면 후진을 못함 작동 종료
            if(map[ny][nx] != 1) Q.push(make_pair(ny, nx));
        }
    }
    return cnt;
}

int main() {
    cin >> N >> M >> r >> c >> direction;
    map.resize(N, vector<int>(M));
    
    for(int i = 0; i < N; i++)
        for(int j = 0; j < M; j++) cin >> map[i][j];
    cout << solve() << "\n";
    return 0;
}
