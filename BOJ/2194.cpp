//
//  2194.cpp
//  test
//
//  Created by 주성호 on 2020/07/15.
//  Copyright © 2020 주성호. All rights reserved.
//
//  https://www.acmicpc.net/problem/2194
//  BOJ2194 유닛 이동시키기 : 구현, 탐색, 너비 우선 탐색, 그래프 이론, 그래프 탐색

#include <iostream>
#include <queue>
using namespace std;

typedef pair<int, int> pii;
int N, M, K, A, B;
bool map[500][500], visited[500][500];
pii s, e;

int dy[] = {-1, 1, 0, 0};
int dx[] = {0, 0, -1, 1};

bool collisionCheck(int y, int x) {
    // 범위에서 벗어남
    if(y < 0 || x < 0 || y + A - 1 >= N || x + B - 1 >= M) return false;
    
    for(int ny = 0; ny < A; ny++) {
        for(int nx = 0; nx < B; nx++) {
            // 장애물이 있을 경우
            if(map[y + ny][x + nx]) return false;
        }
    }
    return true;
}

int traversal() {
    int ans = -1;
    queue<pair<int, pii> > Q;
    Q.push(make_pair(0, s));
    visited[s.first][s.second] = true;
    
    while(!Q.empty()) {
        int dist = Q.front().first;
        pii p = Q.front().second;
        Q.pop();
        
        if(p.first == e.first && p.second == e.second) {
            ans = dist;
            break;
        }
        
        for(int i = 0; i < 4; i++) {
            int ny = dy[i] + p.first;
            int nx = dx[i] + p.second;
            
            if(!visited[ny][nx] && collisionCheck(ny, nx)) {
                visited[ny][nx] = true;
                Q.push(make_pair(dist + 1, make_pair(ny, nx)));
            }
        }
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int x, y;
    cin >> N >> M >> A >> B >> K;
    
    for(int i = 0; i < K; i++) {
        cin >> y >> x;
        map[y - 1][x - 1] = true;
    }
    
    cin >> y >> x;
    s = make_pair(y - 1, x - 1);
    cin >> y >> x;
    e = make_pair(y - 1, x - 1);
    
    
    cout << traversal() << "\n";
    
    return 0;
}
