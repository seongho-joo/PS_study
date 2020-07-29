//
//  14499.cpp
//  test
//
//  Created by 주성호 on 2020/07/29.
//  Copyright © 2020 주성호. All rights reserved.
//
//  https://www.acmicpc.net/problem/14499
//  BOJ1499 주사위 굴리기 : 시뮬레이션

#include <iostream>
#include <vector>
using namespace std;
typedef pair<int, int> pii;

int N, M, y, x, K;
vector<vector<int> > map;
int dice[6];
// 0-동, 1-서, 2-북, 3-남
int dy[] = {0, 0, -1, 1};
int dx[] = {1, -1, 0, 0};

int facing(int n) {
    switch (n) {
        case 0: return 5;
        case 1: return 4;
        case 2: return 3;
        case 3: return 2;
        case 4: return 1;
        default: return 0;
    }
}

void solve() {
    int top = 0, bottom = 5, left = 3, right = 2, front = 4, back = 1;
    int direction;
    while(K--) {
        cin >> direction;
        direction -= 1;
        int ny = y + dy[direction];
        int nx = x + dx[direction];
        if(ny >= 0 && ny < N && nx >= 0 && nx < M) {
            y = ny;
            x = nx;
            switch (direction) {
                case 0:
                    // 동쪽으로 굴림
                    bottom = right;
                    right = top;
                    left = facing(right);
                    top = facing(bottom);
                    break;
                case 1:
                    // 서쪽으로 굴림
                    bottom = left;
                    left = top;
                    right = facing(left);
                    top = facing(bottom);
                    break;
                case 2:
                    // 북쪽으로 굴림
                    bottom = back;
                    back = top;
                    top = facing(bottom);
                    front = facing(back);
                    break;
                case 3:
                   // 남쪽으로 굴림
                    bottom = front;
                    front = top;
                    top = facing(bottom);
                    back = facing(front);
                    break;
            }
            if(map[y][x] == 0) map[y][x] = dice[bottom];
            else {
                dice[bottom] = map[y][x];
                map[y][x] = 0;
            }
            cout << dice[top] << "\n";
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M >> y >> x >> K;
    map.resize(N, vector<int>(M));
    
    for(int i = 0; i < N; i++)
        for(int j = 0; j < M; j++) cin >> map[i][j];
    
    solve();
}
