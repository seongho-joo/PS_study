//
//  15683.cpp
//  test
//
//  Created by 주성호 on 2020/09/03.
//  Copyright © 2020 주성호. All rights reserved.
//
//  https://www.acmicpc.net/problem/15683
//  BOJ15683 감시 : 구현, 브루트포스 알고리즘, 시뮬레이션

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct CCTV {
    int num, x, y;
    CCTV() : num(0), x(0), y(0) {}
    CCTV(int n, int y, int x) : num(n), y(y), x(x) {}
};
vector<vector<int> > map;
vector<CCTV> cctv;
int N, M, res = 987654321;
int rotation[] = {-1, 4, 2, 4, 4, 1};

void getBlindSpot() {
    int cnt = 0;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            if(map[i][j] == 0) cnt += 1;
        }
    }
    res = min(res, cnt);
}

void update(int dir, int y, int x) {
    dir %= 4;
    
    switch (dir) {
        case 0: // 동
            for(int i = x + 1; i < M; i++) {
                if(map[y][i] == 6) {
                    break;
                } else if(map[y][i] == 0) {
                    map[y][i] = -1;
                }
            }
            break;
        case 1: // 남
            for(int i = y + 1; i < N; i++) {
                if(map[i][x] == 6) {
                    break;
                } else if(map[i][x] == 0) {
                    map[i][x] = -1;
                }
            }
            break;
        case 2: // 서
            for(int i = x - 1; i >= 0; i--) {
                if(map[y][i] == 6) {
                    break;
                } else if(map[y][i] == 0) {
                    map[y][i] = -1;
                }
            }
            break;
        default: // 북
            for(int i = y - 1; i >= 0; i--) {
                if(map[i][x] == 6) {
                    break;
                } else if(map[i][x] == 0) {
                    map[i][x] = -1;
                }
            }
            break;
    }
}

void dfs(int idx) {
    if(idx == cctv.size()) {
        getBlindSpot();
        return;
    }
    vector<vector<int> > copyMap;
    int type = cctv[idx].num;
    int y = cctv[idx].y, x = cctv[idx].x;
    for(int i = 0; i < rotation[type]; i++) {
        copyMap = map;
        // 0 동쪽 1 남쪽 2 서쪽 3 북쪽
        switch (type) {
            case 1:
                update(i, y, x);
                break;
            case 2:
                update(i, y, x);
                update(i + 2, y, x);
                break;
            case 3:
                update(i, y, x);
                update(i + 1, y, x);
                break;
            case 4:
                update(i, y, x);
                update(i + 1, y, x);
                update(i + 2, y, x);
                break;
            default:
                update(i, y, x);
                update(i + 1, y, x);
                update(i + 2, y, x);
                update(i + 3, y, x);
                break;
        }
        dfs(idx + 1);
        map = copyMap;
    }
}

int main() {
    cin >> N >> M;
    map.resize(N, vector<int>(M));
    
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++) {
            cin >> map[i][j];
            if(map[i][j] > 0 && map[i][j] < 6)
                cctv.push_back({map[i][j], i, j});
        }
    }
    
    dfs(0);
    
    cout << res << "\n";
    
    return 0;
}
