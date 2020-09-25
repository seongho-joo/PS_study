//
//  11724.cpp
//  PS_Study
//
//  Created by 주성호 on 2020/09/25.
//  Copyright © 2020 주성호. All rights reserved.
//
//  https://www.acmicpc.net/problem/11724
//  BOJ11724 연결 요소의 개수 : 그래프 이론, 그래프 탐색, 너비 우선 탐색, 깊이 우선 탐색

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX = 1000;
vector<vector<int> > adj;
bool v[MAX];

void dfs(int cur) {
    v[cur] = true;
    
    for(int i = 0; i < adj[cur].size(); i++) {
        int next = adj[cur][i];
        if(!v[next]) {
            dfs(next);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N, M;
    cin >> N >> M;
    adj.resize(N);
    
    for(int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        adj[u - 1].push_back(v - 1);
        adj[v- 1].push_back(u - 1);
    }
    // 연결 요소의 개수
    int res = 0;
    
    for(int i = 0; i < N; i++) {
        if(!v[i]) {
            res += 1;
            dfs(i);
        }
    }
    
    cout << res << "\n";

    return 0;
}
