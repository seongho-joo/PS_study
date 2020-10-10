//
//  2252.cpp
//  test
//
//  Created by 주성호 on 2020/10/10.
//  Copyright © 2020 주성호. All rights reserved.
//
//  https://www.acmicpc.net/problem/2252
//  BOJ2252 줄 세우기 : 그래프 이론, 위상 정렬

#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;

const int MAX = 32001;
int n, m;
int indgree[MAX] = {0, };
int seq[MAX] = {0, };
vector<vector<int> > adj;

int main() {
    cin >> n >> m;
    adj.resize(n + 1);
    for(int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        indgree[v] += 1;
    }
    queue<int> Q;
    for(int i = 1; i <= n; i++) {
        if(indgree[i] == 0) Q.push(i);
    }
    for(int i = 1; i <= n; i++) {
        if(!Q.empty()) {
            int cur = Q.front(); Q.pop();
            seq[i] = cur;
            for(auto next : adj[cur]) {
                indgree[next] -= 1;
                if(indgree[next] == 0) Q.push(next);
            }
        }
    }
    for(int i = 1; i <= n; i++) cout << seq[i] << " ";
    cout << "\n";
    return 0;
}
