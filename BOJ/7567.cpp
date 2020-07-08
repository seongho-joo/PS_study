//
//  7567.cpp
//  OnlineJudge
//
//  Created by 주성호 on 2020/04/23.
//  Copyright © 2020 주성호. All rights reserved.
//
//  토마토 https://www.acmicpc.net/problem/7576

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef pair<int, int> pii;
vector<vector<int> > storage;
queue<pii> Q;
int M, N, date, tomato, MAX, seg, cnt;
int dy[] = {1, 0, -1, 0};
int dx[] = {0, 1, 0, -1};

void BFS() {
    bool flag = false;
    while(!Q.empty()){
        cnt = 0;
        flag = false;
        for(int j = 0; j < seg; j++) {
            int y = Q.front().first;
            int x = Q.front().second;
            Q.pop();
            for(int i = 0; i < 4; i++) {
                int ny = y + dy[i];
                int nx = x + dx[i];
                if(ny > -1 && nx > -1 && ny < N && nx < M && storage[ny][nx] == 0) {
                    flag = true;
                    storage[ny][nx] = 1;
                    tomato += 1;
                    cnt += 1;
                    Q.push(make_pair(ny, nx));
                }
            }
        }
        seg = cnt;
        if(flag)
            date += 1;
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> M >> N;
    MAX = M * N;
    storage.resize(N, vector<int>(M));
    
    for(int i = 0; i < N; i++)
        for(int j = 0; j < M; j++) cin >> storage[i][j];

    for(int i = 0; i < N; i++)
        for(int j = 0; j < M; j++) {
            if(storage[i][j] == -1) MAX -= 1;
            else if(storage[i][j] == 1) {
                seg += 1;
                tomato += 1;
                Q.push(make_pair(i, j));
            }
        }
    BFS();
    
    cout << (MAX == tomato ? date : -1) << '\n';
}
