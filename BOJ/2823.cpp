//
//  2823.cpp
//  test
//
//  Created by 주성호 on 2020/07/13.
//  Copyright © 2020 주성호. All rights reserved.
//
//  https://www.acmicpc.net/problem/2823
//  BOJ2823 유턴 싫어 : 배열, 구현

#include <iostream>
#include <vector>
using namespace std;

vector<vector<char> > road;
int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};
int r, c;

bool dfs() {
    for(int y = 0; y < r; y++) {
        for(int x = 0; x < c; x++) {
            if(road[y][x] == '.') {
                int path = 0;
                for(int i = 0; i < 4; i++) {
                    int ny = dy[i] + y;
                    int nx = dx[i] + x;
                    if(ny >= 0 && nx >= 0 && ny < r && nx < c && road[ny][nx] == '.')
                        path += 1;
                }
                if(path <= 1) return false;
            }
        }
    }
    return true;
}

int main() {
    cin >> r >> c;
    
    road.resize(r, vector<char>(c));
    
    for(int i = 0; i < r; i++)
        for(int j = 0; j < c; j++) cin >> road[i][j];
    
    cout << (dfs() ? 0 : 1) << "\n";
    
    return 0;
}
