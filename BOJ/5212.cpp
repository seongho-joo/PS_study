//
//  5212.cpp
//  test
//
//  Created by 주성호 on 2020/07/13.
//  Copyright © 2020 주성호. All rights reserved.
//
//  https://www.acmicpc.net/problem/5212
//  BOJ5212 지구 온난화 : 구현

#include <iostream>
#include <vector>
#include <string>
using namespace std;

typedef pair<int, int> pii;
int r, c;
vector<string> map;
vector<pii> coor;

int dy[] = {-1, 1, 0, 0};
int dx[] = {0, 0, -1, 1};
int minY = 987654321, minX = 987654321, maxY = -1, maxX = -1;

void dfs() {
    for(int y = 0; y < r; y++) {
        for(int x = 0; x < c; x++) {
            if(map[y][x] == 'X') {
                int sea = 0;
                for(int i = 0; i < 4; i++) {
                    int ny = dy[i] + y;
                    int nx = dx[i] + x;
                    if(ny >= 0 && nx >= 0 && ny < r && nx < c && map[ny][nx] == '.') {
                        sea += 1;
                    }
                }
                if(x == 0) sea += 1;
                if(x + 1 == c) sea += 1;
                if(y == 0) sea += 1;
                if(y + 1 == r) sea += 1;
                
                if(sea >= 3) coor.push_back(make_pair(y, x));
            }
        }
    }
    for(int i = 0; i < coor.size(); i++)
        map[coor[i].first][coor[i].second] = '.';
    
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            if(map[i][j] == 'X') {
                minY = minY > i ? i : minY;
                maxY = maxY < i ? i : maxY;
                minX = minX > j ? j : minX;
                maxX = maxX < j ? j : maxX;
            }
        }
    }
}

int main() {
    cin >> r >> c;
    map.resize(r);
    
    for(int i = 0; i < r; i++) cin >> map[i];
    
    dfs();
    
    for(int i = minY; i <= maxY; i++) {
        for(int j = minX; j <= maxX; j++) {
            cout << map[i][j];
        }
        cout << "\n";
    }
    
    return 0;
}
