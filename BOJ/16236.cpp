//
//  16236.cpp
//  test
//
//  Created by 주성호 on 2020/09/07.
//  Copyright © 2020 주성호. All rights reserved.
//
//  https://www.acmicpc.net/problem/16236
//  BOJ16236 아기 상어 : 구현, 그래프 이론, 그래프 탐색, 너비 우선 탐색, 시뮬레이션

#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;

typedef pair<int, int> pii;
typedef pair<pii, int> ppi;

struct shark {
    // 상어 위치와 크기 구조체
    int y, x, size;
    shark() : y(0), x(0), size(2) {}
    shark(int y, int x, int s) : y(y), x(x), size(s) {}
};
struct Fish {
    // 먹이 후보와 거리
    int y, x, time;
    // 거리가 가깝고 y가 제일 작으며 x가 작으면 우선순위가 높음
    bool operator < (const Fish& a) const {
        if(time != a.time) return time > a.time;
        else if(y != a.y) return y > a.y;
        else if(x != a.x) return x > a.x;
        else return false;
    }
};
vector<vector<int> > map;
int N;
bool visited[20][20];
int dy[] = {-1, 1, 0, 0};
int dx[] = {0, 0, -1, 1};
pii s;

void solution() {
    queue<shark> Q;
    Q.push(shark(s.first, s.second, 2));
    // 먹이 수
    int cnt = 0, res = 0;
    
    while(!Q.empty()) {
        shark s = Q.front();
        Q.pop();
        
        memset(visited, false, sizeof(visited));
        // 경로 우선순위 큐
        priority_queue<Fish> path;
        path.push({s.y, s.x, 0});
        visited[s.y][s.x] = true;
        
        while(!path.empty()) {
            int size = (int)path.size();
            // 먹이 우선순위 큐
            priority_queue<ppi, vector<ppi>, greater<ppi> > candidate;
            
            for(int i = 0; i < size; i++) {
                Fish cur = path.top();
                path.pop();
                
                for(int j = 0; j < 4; j++) {
                    int ny = dy[j] + cur.y;
                    int nx = dx[j] + cur.x;
                    if(0 <= ny && 0 <= nx && ny < N && nx < N) {
                        // 지나갈 수 있을 경우
                        if(!visited[ny][nx] && map[ny][nx] <= s.size) {
                            path.push({ny, nx, cur.time + 1});
                            visited[ny][nx] = true;
                            // 먹이 후보 중 하나
                            if(map[ny][nx] >= 1 && map[ny][nx] < s.size) {
                                candidate.push({ {ny, nx}, cur.time + 1 });
                            }
                        }
                    }
                }
            }
            // 우선순위가 높은 먹이를 먹고 현재 위치를 Q에 넣음
            if(!candidate.empty()) {
                cnt += 1;
                int y = candidate.top().first.first;
                int x = candidate.top().first.second;
                int time = candidate.top().second;
                
                if(s.size == cnt) {
                    Q.push({ y, x, s.size + 1 });
                    cnt = 0;
                } else {
                    Q.push({ y, x, s.size });
                }
                // 먹이를 먹었으니 0으로 초기화
                map[y][x] = 0;
                res += time;
                break;
            }
        }
    }
    
    cout << res << "\n";
}
 
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    map.resize(N, vector<int>(N));
    
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cin >> map[i][j];
            if(map[i][j] == 9) {
                s = {i, j};
                map[i][j] = 0;
            }
        }
    }
    
    solution();
    
    return 0;
}
