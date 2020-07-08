//
//  2636.cpp
//  OnlineJudge
//
//  Created by 주성호 on 2020/04/23.
//  Copyright © 2020 주성호. All rights reserved.
//
//  https://www.acmicpc.net/problem/2636 : 치즈

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

typedef pair<int, int> pii;
vector<vector<int> > rec,outside;
vector<vector<bool> > visit;
vector<pii> coor;
int col, row, hour, ans, cheeze;
int dy[] = {0, 1, 0, -1};
int dx[] = {1, 0, -1, 0};

void initOutside() {
    queue<pii> out;
    out.push(make_pair(0, 0));
    outside[0][0] = 1;
    
    while(!out.empty()) {
        pii c = out.front(); out.pop();
        for(int i = 0; i < 4; i++) {
            int ny = c.first + dy[i];
            int nx = c.second + dx[i];
            if(ny > -1 && nx > -1 && ny < row && nx < col) {
                // 공기인 부분
                if(rec[ny][nx] == 0 && outside[ny][nx] != 1) {
                    outside[ny][nx] = 1;
                    out.push(make_pair(ny, nx));
                }
            }
        }
    }
    for(int i = 0; i < row; i++)
        for(int j = 0; j < col; j++)
            if(outside[i][j] == -1) outside[i][j] = 0;
}

bool isOutside(int y, int x) {
    for(int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny > -1 && nx > -1 && ny < row && nx < col && outside[ny][nx] == 1) return true;
    }
    return false;
}

void DFS(int y, int x) {
    visit[y][x] = true;
    coor.push_back(make_pair(y, x));
    
    for(int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny > -1 && nx > -1 && ny < row && nx < col && rec[ny][nx] == 1 && !visit[ny][nx] && isOutside(ny, nx)) {
            DFS(ny, nx);
        }
    }
}


void meltDown() {
    for(int i = 0; i < coor.size(); i++) {
        rec[coor[i].first][coor[i].second] = 0;
        outside[coor[i].first][coor[i].second] = 1;
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> row >> col;
    rec.resize(row, vector<int>(col));
    outside.resize(row, vector<int>(col, -1));
    visit.resize(row, vector<bool>(col, false));
    
    for(int i = 0; i < row; i++)
        for(int j = 0; j < col; j++) {
            cin >> rec[i][j];
            if(rec[i][j] == 1) cheeze += 1;
        }
    
    initOutside();
    
    while(cheeze != 0) {
        ans = 0;
        initOutside();
        for(int i = 0; i < row; i++) {
            for(int j = 0; j < col; j++) {
                if(rec[i][j] == 1 && !visit[i][j] && isOutside(i, j)) DFS(i, j);
            }
        }
        meltDown();
        cheeze -= coor.size();
        ans += coor.size();
        coor.clear();
        hour += 1;
        fill(outside.begin(), outside.end(), vector<int>(col, -1));
    }
    
    cout << hour << '\n' << ans << '\n';
    
    return 0;
}
