//
//  2583.cpp
//  test
//
//  Created by 주성호 on 2020/10/17.
//  Copyright © 2020 주성호. All rights reserved.
//
//  https://www.acmicpc.net/problem/2583
//  BOJ2583 영역 구하기 : 그래프 이론, 그래프 탐색, 정렬, 깊이 우선 탐색

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int> > paper;
vector<vector<bool> > visited;
vector<int> res;

int N, M;
int dy[] = {-1, 1, 0, 0};
int dx[] = {0, 0, -1, 1};
int c = 0;

int dfs(int y, int x) {
    visited[y][x] = true;
    c += 1;
    for(int i = 0; i < 4; i++) {
        int ny = dy[i] + y;
        int nx = dx[i] + x;
        if(ny >= 0 && nx >= 0 && ny < N && nx < M) {
            if(!visited[ny][nx] && paper[ny][nx] == 0) {
                dfs(ny, nx);
            }
        }
    }
    return c;
}

int main() {
    int K, y, x, dy, dx;
    cin >> N >> M >> K;
    
    paper.resize(N,vector<int>(M, 0));
    visited.resize(N,vector<bool>(M, false));
    
    while (K--) {
        cin >> x >> y >> dx >> dy;
        for(int i = y; i < dy; i++) {
            for(int j = x; j < dx; j++) {
                paper[i][j] = 1;
            }
        }
    }
    
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            if(paper[i][j] == 0 && !visited[i][j]) {
                c = 0;
                res.push_back(dfs(i, j));
            }
        }
    }
    
    sort(res.begin(), res.end());
    cout << res.size() << "\n";
    for(int i : res) {
        cout << i << " ";
    }
    return 0;
}
