//
//  2606.cpp
//  OnlineJudge
//
//  Created by 주성호 on 2020/05/30.
//  Copyright © 2020 주성호. All rights reserved.
//
//  https://www.acmicpc.net/problem/2606 바이러스

#include <iostream>
#include <vector>
using namespace std;

vector<vector<int> > network;
vector<bool> visited;
int n, e, cnt = 0;

void makeNetwork() {
    int u, v;
    for(int i = 0; i < e; i++) {
        cin >> u >> v;
        network[u].push_back(v);
        network[v].push_back(u);
    }
}

void dfs(int s) {
    visited[s] = true;
    for(int next : network[s]) {
        if(!visited[next]) {
            cnt += 1;
            dfs(next);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> e;
    
    visited.resize(n + 1, false);
    network.resize(n + 1);
    makeNetwork();
    dfs(1);
    cout << cnt << "\n";
    return 0;
}
