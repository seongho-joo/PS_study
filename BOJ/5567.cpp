//
//  5567.cpp
//  OnlineJudge
//
//  Created by 주성호 on 2020/06/30.
//  Copyright © 2020 주성호. All rights reserved.
//
//  https://www.acmicpc.net/problem/5567 결혼식

#include <iostream>
#include <vector>
using namespace std;

vector<vector<bool> > adj;
vector<bool> visited;
vector<int> list;

int main() {
    int n, m, ans = 0;
    cin >> n >> m;
    adj.resize(n + 1, vector<bool>(n + 1));
    visited.resize(n + 1, false);
    
    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        if (u == 1) {
            ans += 1;
            list.push_back(v);
            visited[v] = true;
        }
        adj[u][v] = true;
        adj[v][u] = true;
    }
    
    for(auto v : list) {
        for(int i = 2; i <= n; i++) {
            if(adj[v][i] && !visited[i]) {
                ans += 1;
                visited[i] = true;
            }
        }
    }
    
    cout << ans << "\n";
    
    return 0;
}
