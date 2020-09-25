//
//  1743.cpp
//  test
//
//  Created by 주성호 on 2020/09/25.
//  Copyright © 2020 주성호. All rights reserved.
//
//  https://www.acmicpc.net/problem/1743
//  BOJ1743 음식물 피하기 : 그래프 이론, 그래프 탐색, 너비 우선 탐색, 깊이 우선 탐색

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<vector<int> > map;
vector<vector<bool> > v;
int dy[] = {1, -1, 0, 0};
int dx[] = {0, 0, -1, 1};
int n, m, k, cnt = 0;

void dfs(int y, int x) {
    cnt += 1;
    v[y][x] = true;
    
    for(int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny >= 0 && nx >= 0 && ny < n && nx < m) {
            if(!v[ny][nx] && map[ny][nx] == 1) {
                dfs(ny, nx);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m >> k;
    map.resize(n, vector<int>(m, 0));
    v.resize(n, vector<bool>(m, false));
    
    for(int i = 0; i < k; i++) {
        int r, c;
        cin >> r >> c;
        map[r - 1][c - 1] = 1;
    }
    int res = -1;
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(!v[i][j] && map[i][j] == 1) {
                cnt = 0;
                dfs(i, j);
                res = max(cnt, res);
            }
        }
    }
    cout << res << "\n";
    return 0;
}
