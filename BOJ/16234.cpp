//
//  16234.cpp
//  test
//
//  Created by 주성호 on 2020/11/04.
//  Copyright © 2020 주성호. All rights reserved.
//
//  https://www.acmicpc.net/problem/16234
//  BOJ16234 인구 이동 : 구현, 그래프 이론, 그래프 탐색, 너비 우선 탐색, 시뮬레이션

#include <iostream>
#include <queue>
#include <vector>
#include <cmath>

using namespace std;
typedef pair<int, int> pii;

int N, L, R;
int dy[] = {-1, 1, 0, 0};
int dx[] = {0, 0, -1, 1};
vector<vector<int> > map;
vector<vector<bool> > visited;
vector<pii> country;

int solution(int y, int x) {
    int ret = map[y][x];
    queue<pii> Q;
    Q.push(pii(y, x));
    visited[y][x] = true; country.push_back(pii(y,x));
    
    while(!Q.empty()) {
        pii cur = Q.front(); Q.pop();
        for(int i = 0; i < 4; i++) {
            int ny = dy[i] + cur.first;
            int nx = dx[i] + cur.second;
            if(ny >= 0 && nx >= 0 && ny < N && nx < N) {
                int diff = abs(map[cur.first][cur.second] - map[ny][nx]);
                // 두 나라간의 인구 수 차이가 L 이상이고 R 이하이면 국경선이 열림
                if(!visited[ny][nx] && diff <= R && diff >= L) {
                    ret += map[ny][nx];
                    visited[ny][nx] = true;
                    Q.push(pii(ny, nx));
                    country.push_back(pii(ny,nx));
                }
            }
        }
    }
    
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> L >> R;
    
    map.resize(N, vector<int>(N));
    visited.resize(N, vector<bool>(N, false));
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cin >> map[i][j];
        }
    }
    int res = 0;
    
    while(true) {
        fill(visited.begin(), visited.end(), vector<bool>(N, false));
        country.clear();
        bool flag = false;
        
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < N; j++) {
                if(!visited[i][j]) {
                    int ret = solution(i, j);
                    if(country.size() != 1) {
                        flag = true;
                        int avg = ret / country.size();
                        // 인구이동으로 인한 인구 수 변경
                        for(pii i : country) {
                            map[i.first][i.second] = avg;
                        }
                        country.clear();
                    } else {
                        country.clear();
                    }
                }
            }
        }
        if(flag) {
            // 인구이동 발생
            res += 1;
        } else {
            // 더 이상 인구이동이 없을 때 while문 종료
            break;
        }
    }
    
    cout << res << "\n";
    
    return 0;
}
