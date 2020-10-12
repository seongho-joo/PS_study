//
//  1261.cpp
//  test
//
//  Created by 주성호 on 2020/10/12.
//  Copyright © 2020 주성호. All rights reserved.
//
//  https://www.acmicpc.net/problem/1261
//  BOJ1261 알고스팟 : 그래프 이론, 자료 구조, 다익스트라, 우선순위 큐

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct Coords {
    int y, x, cnt;
    Coords() : y(0), x(0), cnt(0) {}
    Coords(int y, int x, int cnt) : y(y), x(x), cnt(cnt) {}
    bool operator < (const Coords A) const {
        return cnt > A.cnt;
    }
};

vector<string> map;
vector<vector<bool> > visited;
int dy[] = {-1, 1, 0, 0};
int dx[] = {0, 0, -1, 1};

int N, M;

int solution() {
    priority_queue<Coords> pq;
    pq.push(Coords(0, 0, 0));
    visited[0][0] = true;
    while(!pq.empty()) {
        Coords cur = pq.top();
        pq.pop();
        if(cur.y == M - 1 && cur.x == N - 1) {
            return cur.cnt;
        }
        for(int i = 0; i < 4; i++) {
            int ny = cur.y + dy[i];
            int nx = cur.x + dx[i];
            if(ny >= 0 && nx >= 0 && ny < M && nx < N) {
                if(!visited[ny][nx]) {
                    visited[ny][nx] = true;
                    int cnt = cur.cnt;
                    if(map[ny][nx] == '1') {
                        cnt += 1;
                    }
                    pq.push(Coords(ny, nx, cnt));
                }
            }
        }
    }
    return 0;
}

int main() {
    cin >> N >> M;
    map.resize(M);
    visited.resize(M, vector<bool>(N, false));
    
    for(int i = 0; i < M; i++) {
        cin >> map[i];
    }
    
    int res = solution();
    cout << res << "\n";
    
    return 0;
}
