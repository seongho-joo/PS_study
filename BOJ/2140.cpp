//
//  2140.cpp
//  test
//
//  Created by 주성호 on 2020/07/16.
//  Copyright © 2020 주성호. All rights reserved.
//
//  https://www.acmicpc.net/problem/2140
//  BOJ2140 지뢰찾기 : 구현

#include <iostream>
#include <vector>
using namespace std;

int N, mine;
int dy[] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dx[] = {0, -1, -1, -1, 0, 1, 1, 1};
vector<vector<char> > map;

int pow(int n) {
    return n * n;
}

void solve() {
    bool flag;
    for(int i = 1; i < N - 1; i++) {
        for(int j = 1; j  < N - 1; j++) {
            flag = false;
            for(int k = 0; k < 8; k++) {
                int ny = dy[k] + i;
                int nx = dx[k] + j;
                if(map[ny][nx] == '#') continue;
                if(map[ny][nx] == '0') flag = true;
            }
            if(flag) mine -= 1;
            else {
                for(int k = 0; k < 8; k++) {
                    int ny = dy[k] + i;
                    int nx = dx[k] + j;
                    if(map[ny][nx] == '#' || map[ny][nx] == '0') continue;
                    map[ny][nx] -= 1;
                }
            }
        }
    }
}

int main() {
    cin >> N;
    map.resize(N, vector<char>(N));
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++) cin >> map[i][j];
    
    if(N < 3) mine = 0;
    else {
        mine = pow(N - 2);
        solve();
    }
    cout << mine << "\n";
    return 0;
}
