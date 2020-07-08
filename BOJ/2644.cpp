//
//  2644.cpp
//  OnlineJudge
//
//  Created by 주성호 on 2020/05/21.
//  Copyright © 2020 주성호. All rights reserved.
//
//  https://www.acmicpc.net/problem/2644 촌수계산

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<int> > family;
vector<bool> visited;
vector<int> depth;
bool flag = false;

void bfs(int s, int t) {
    queue<int> Q;
    Q.push(s);
    visited[s] = true;
    while(!Q.empty()) {
        int cur = Q.front(); Q.pop();
        for(int next : family[cur]) {
            if(!visited[next]) {
                visited[next] = true;
                depth[next] = depth[cur] + 1;
                Q.push(next);
            }
        }
    }
}

int main() {
    int n, a, b, r; // 사람 수, a와 b의 촌수 관계, 관계 수
    cin >> n >> a >> b >> r;
    family.resize(n + 1);
    depth.resize(n + 1, 0);
    visited.resize(n + 1, false);
    
    for(int i = 0; i < r; i++) {
        int parent, child;
        cin >> parent >> child;
        family[parent].push_back(child);
        family[child].push_back(parent);
    }
    bfs(a, b);
    cout << (depth[b] == 0 ? -1 : depth[b]) << "\n";
    
    return 0;
}
