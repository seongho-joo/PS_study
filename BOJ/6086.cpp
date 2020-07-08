//
//  6086.cpp
//  OnlineJudge
//
//  Created by 주성호 on 2020/04/20.
//  Copyright © 2020 주성호. All rights reserved.
//
//  https://www.acmicpc.net/problem/6086
//  최대 유량
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX = 52;
const int INF = 987654321;
int c[MAX][MAX];
int f[MAX][MAX];
vector<int> near[MAX];

int CtoI(char c) {
    if(c < 'Z') return c - 'A';
    return c - 'a' + 26;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N;
    cin >> N;
    
    for(int i = 0; i < N; i++) {
        char u, v;
        int w;
        cin >> u >> v >> w;
        u = CtoI(u); v = CtoI(v);
        c[u][v] = c[v][u] += w;
        near[u].push_back(v);
        near[v].push_back(u);
    }
    
    int s = CtoI('A'), e = CtoI('Z'), total = 0;
    
    while(true) {
        int prev[MAX];
        fill(prev, prev + MAX, -1);
        queue<int> que;
        que.push(s);
        while(!que.empty() && prev[e] == - 1) {
            int cur = que.front();
            que.pop();
            for(int i = 0; i < near[cur].size(); i++) {
                int next = near[cur][i];
                if(c[cur][next] - f[cur][next] > 0 && prev[next] == -1) {
                    que.push(next);
                    prev[next] = cur;
                    if(next == e) break;
                }
            }
        }
        if(prev[e] == -1) break;
        
        int flow = INF;
        for(int i = e; i != s; i = prev[i]) flow = min(flow, c[prev[i]][i] - f[prev[i]][i]);
        for(int i = e; i != s; i = prev[i]) {
            f[prev[i]][i] += flow;
            f[i][prev[i]] -= flow;
        }
        total += flow;
    }
    cout << total << '\n';
    
    return 0;
}
