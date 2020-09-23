//
//  2573.cpp
//  PS_Study
//
//  Created by 주성호 on 2020/09/23.
//  Copyright © 2020 주성호. All rights reserved.
//
//  https://www.acmicpc.net/problem/2573
//  BOJ2573 빙산 : 구현, 그래프 이론, 그래프 탐색, 너비 우선 탐색, 깊이 우선 탐색

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef pair<int, int> pii;
struct Ice {
    int y, x, cnt;
    Ice() : y(0), x(0), cnt(0) {}
    Ice(int y, int x, int cnt) : y(y), x(x), cnt(cnt) {}
};
vector<vector<int> > map;
vector<Ice> melting;
int dy[] = {0, 0, 1, -1};
int dx[] = {1, -1, 0, 0};
int N, M;
int iceberg = 0;
pii s;
// 현재 좌표 주변에 바다가 얼마나 있는지 카운팅
int getSeaCount(int y, int x) {
    int cnt = 0;
    for(int i = 0; i < 4; i++) {
        int ny = dy[i] + y;
        int nx = dx[i] + x;
        if(ny >= 0 && ny < N && nx >= 0 && nx < M && map[ny][nx] == 0) {
            cnt += 1;
        }
    }
    return cnt;
}
// BFS를 이용해 빙산이 분리 되어있는지 확인
bool solution() {
    melting.clear();
    vector<vector<bool> > v(N, vector<bool>(M, false));
    queue<pii> Q;
    Q.push(s);
    v[s.first][s.second] = true;
    while(!Q.empty()) {
        pii cur = Q.front();
        Q.pop();
        melting.push_back(Ice(cur.first, cur.second, getSeaCount(cur.first, cur.second)));
        for(int i = 0; i < 4; i++) {
            int ny = cur.first + dy[i];
            int nx = cur.second + dx[i];
            if(ny >= 0 && ny < N && nx >= 0 && nx < M) {
                if(map[ny][nx] != 0 && !v[ny][nx]) {
                    Q.push({ny, nx});
                    v[ny][nx] = true;
                }
            }
        }
    }
    if(melting.size() == iceberg) return true;
    else return false;
}

int main() {
    cin >> N >> M;
    map.resize(N, vector<int>(M));
    
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cin >> map[i][j];
            if(map[i][j] != 0) iceberg += 1;
        }
    }
    int res = 0;
    while(true) {
        s = {0, 0};
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < M; j++) {
                if(map[i][j] != 0) {
                    s = {i, j};
                    break;
                }
            }
            if(s.first != 0 && s.second != 0) break;
        }
        res += 1;
        if(!solution()) break;
        // 주변 바다 개수만큼 빙산 높이를 줄임
        for(int i = 0; i < (int)melting.size(); i++) {
            Ice ice = melting[i];
            map[ice.y][ice.x] -= ice.cnt;
            if(map[ice.y][ice.x] < 0) map[ice.y][ice.x] = 0;
            if(map[ice.y][ice.x] == 0) iceberg -= 1;
        }
        if(iceberg == 0) {
            cout << 0 << "\n";
            return 0;
        }
    }
    
    cout << res -1 << "\n";
    
    return 0;
}
