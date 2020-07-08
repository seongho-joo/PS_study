//
//  2468.cpp
//  OnlineJudge
//
//  Created by 주성호 on 2020/04/23.
//  Copyright © 2020 주성호. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define fastIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

typedef pair<int, int> pii;
vector<vector<int> > location;
vector<vector<bool> > visit;
queue<pii> Q;
int dy[] = {1, 0, -1, 0};
int dx[] = {0, 1, 0, -1};
int N;

void BFS(int h) {
    while(!Q.empty()) {
        pii coor = Q.front(); Q.pop();
        for(int i = 0; i < 4; i++) {
            int ny = coor.first + dy[i];
            int nx = coor.second + dx[i];
            if(ny > -1 && nx > -1 && ny < N && nx < N && !visit[ny][nx] && location[ny][nx] > h) {
                visit[ny][nx] = true;
                Q.push(make_pair(ny, nx));
            }
        }
    }
}

int main() {
    fastIO();
    cin >> N;
    location.resize(N, vector<int>(N));
    visit.resize(N, vector<bool>(N, false));
    
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++) cin >> location[i][j];
    int cnt = 0, MAX = 0;
    for(int h = 1; h < 101; h++) {
        cnt = 0;
        fill(visit.begin(), visit.end(), vector<bool>(N, false));
        for(int j = 0; j < N; j++) {
            for(int k = 0; k < N; k++) {
                if(location[j][k] > h && !visit[j][k]) {
                    Q.push(make_pair(j, k));
                    visit[j][k] = true;
                    BFS(h);
                    cnt += 1;
                }
            }
            
        }
        MAX = MAX > cnt ? MAX : cnt;
        if(cnt == 0) break;
    }
    cout << (MAX == 0 ? 1 : MAX) << '\n';
    return 0;
}
