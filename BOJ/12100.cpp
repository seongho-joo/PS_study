//
//  12100.cpp
//  test
//
//  Created by 주성호 on 2020/08/31.
//  Copyright © 2020 주성호. All rights reserved.
//
//  https://www.acmicpc.net/problem/12100
//  BOJ12100 2048 (Easy) : 구현, 브루트포스 알고리즘

#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

const int MAX = 5;
vector<vector<int> > board;
int dy[] = {0, 0, 1, -1};
int dx[] = {1, -1, 0, 0};

int N, res, cnt;

void shift(queue<int> &Q, int y, int x, int d) {
    while(!Q.empty()) {
        int num = Q.front(); Q.pop();
        
        if(board[y][x] == 0) {
            board[y][x] = num;
        } else if(board[y][x] == num) {
            board[y][x] *= 2;
            y += dy[d];
            x += dx[d];
        } else {
            y += dy[d];
            x += dx[d];
            board[y][x] = num;
        }
    }
}

void move(int d) {
    queue<int> Q;
    switch (d) {
        case 0:
            for(int i = 0; i < N; i++) {
                for(int j = 0; j < N; j++) {
                    if(board[i][j] != 0) Q.push(board[i][j]);
                    board[i][j] = 0;
                }
                
                int idx = 0;
                shift(Q, i, idx, d);
            }
            break;
        case 1:
            for(int i = 0; i < N; i++) {
                for(int j = N - 1; j >= 0; j--) {
                    if(board[i][j] != 0) Q.push(board[i][j]);
                    board[i][j] = 0;
                }
                int idx = N - 1;
                shift(Q, i, idx, d);
            }
            break;
        case 2:
            for(int i = 0; i < N; i++) {
                for(int j = 0; j < N; j++) {
                    if(board[j][i] != 0) Q.push(board[j][i]);
                    board[j][i] = 0;
                }
                int idx = 0;
                shift(Q, idx, i, d);
            }
            break;
        case 3:
            for(int i = 0; i < N; i++) {
                for(int j = N - 1; j >= 0; j--) {
                    if(board[j][i] != 0) Q.push(board[j][i]);
                    board[j][i] = 0;
                }
                int idx = N - 1;
                shift(Q, idx, i, d);
            }
            break;
    }
}

void dfs(int cnt) {
    if(cnt == MAX) {
        for(int i = 0; i < N; i++)
            for(int j = 0; j < N; j++) res = max(res, board[i][j]);
        return;
    }
    
    vector<vector<int> > copy = board;
    
    for(int i = 0; i < 4; i++) {
        move(i);
        dfs(cnt + 1);
        board = copy;
    }
}

int main() {
    cin >> N;
    board.resize(N, vector<int>(N));
    
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++) cin >> board[i][j];
    
    dfs(0);
    
    cout << res << "\n";
    return 0;
}
