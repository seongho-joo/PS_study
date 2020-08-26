//
//  15686.cpp
//  test
//
//  Created by 주성호 on 2020/08/26.
//  Copyright © 2020 주성호. All rights reserved.
//
//  https://www.acmicpc.net/problem/15686
//  BOJ15686 치킨 배달 : 구현, 브루트포스 알고리즘

#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;
typedef pair<int, int> pii;

vector<vector<int> > map;
vector<pii> home, store;
vector<bool> visited;
int N, M, res = INT_MAX;

void dfs(int s, int cnt) {
    if(cnt == M) {
        int temp = 0;
        for(int i = 0; i < home.size(); i++) {
            int dis = INT_MAX - 1;
            for(int j = 0; j < store.size(); j++) {
                if(visited[j]) {
                    int diff = abs(home[i].first - store[j].first) + abs(home[i].second - store[j].second);
                    dis = min(dis, diff);
                }
            }
            temp += dis;
        }
        res = min(temp, res);
        return;
    }
    for(int i = s; i < store.size(); i++) {
        visited[i] = true;
        dfs(i + 1, cnt + 1);
        visited[i] = false;
    }
    return;
}

int main() {
    cin >> N >> M;
    map.resize(N, vector<int>(N));
    
    for(int i = 0 ; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cin >> map[i][j];
            if(map[i][j] == 1) {
                home.push_back(make_pair(i, j));
            } else if (map[i][j] == 2) {
                store.push_back(make_pair(i, j));
            }
        }
    }
    
    visited.resize(store.size());
    
    dfs(0,0);
    
    cout << res << "\n";
    
    return 0;
}
