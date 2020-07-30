//
//  3190.cpp
//  test
//
//  Created by 주성호 on 2020/07/29.
//  Copyright © 2020 주성호. All rights reserved.
//
//  https://www.acmicpc.net/problem/3190
//  BOJ3190 뱀 : 시뮬레이션

#include <iostream>
#include <vector>
#include <deque>
using namespace std;
typedef pair<int, char> pic;
typedef pair<int, int> pii;

int N, K, L;
int Length = 1, result = 0, direction = 0;
// 0-동, 1-북, 2-서, 3-남
int dy[] = {0, -1, 0, 1};
int dx[] = {1, 0, -1, 0};
vector<vector<int> > map;
vector<pic> turn;
deque<pii> snake;

void solve() {
    int y = 0, x = 0, idx = 0;
    snake.push_back(make_pair(y, x));
    while(true) {
        result += 1;
        int ny = y + dy[direction];
        int nx = x + dx[direction];
        if(ny < 0 || nx < 0 || ny >= N || nx >= N || map[ny][nx] == 2) break;
        else if(map[ny][nx] == 0) {
            map[ny][nx] = 2;
            // 꼬리부분이 사라짐
            pii p = snake.back(); snake.pop_back();
            map[p.first][p.second] = 0;
            snake.push_front(make_pair(ny, nx));
        } else {
            map[ny][nx] = 2;
            snake.push_front(make_pair(ny, nx));
        }
        
        if(idx < L && result == turn[idx].first) {
            if(turn[idx].second == 'L')
                direction = direction + 1 > 3 ? 0 : direction + 1;
            else
                direction = direction - 1 < 0 ? 3 : direction - 1;
            idx += 1;
        }
        y = ny;
        x = nx;
    }
    cout << result << "\n";
}

int main() {
    cin >> N >> K;
    map.resize(N, vector<int>(N));
    while(K--) {
        int y, x;
        cin >> y >> x;
        y -= 1; x -= 1;
        map[y][x] = 1;
    }
    map[0][0] = 2;
    cin >> L;
    turn.resize(L);
    for(int i = 0; i < L; i++) {
        int time;
        char dir;
        cin >> time >> dir;
        turn[i] = make_pair(time, dir);
    }
    solve();
    return 0;
}
