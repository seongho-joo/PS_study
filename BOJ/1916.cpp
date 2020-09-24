//
//  1916.cpp
//  PS_Study
//
//  Created by 주성호 on 2020/09/24.
//  Copyright © 2020 주성호. All rights reserved.
//
//  https://www.acmicpc.net/problem/1916
//  BOJ1916 최소비용 구하기 : 그래프 이론, 다익스트라

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef pair<int, int> pii;
struct vertex {
    int v, e;
    vertex() : v(0), e(0){}
    vertex(int v, int e) : v(v), e(e) {}
};
const int INF = 1987654321;
vector<vector<vertex> > adj;
vector<int> dist;
int n, m, s, e;

void Dijkstra() {
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, s});
    dist[s] = 0;
    
    while(!pq.empty()) {
        int cost = pq.top().first;
        int cur = pq.top().second;
        pq.pop();
        
        if(dist[cur] < cost) continue;
        
        for(int i = 0; i < adj[cur].size(); i++) {
            int next = adj[cur][i].v;
            int nextCost = adj[cur][i].e + cost;
            if(dist[next] > nextCost) {
                dist[next] = nextCost;
                pq.push({nextCost, next});
            }
        }
    }
    cout << dist[e] << "\n";
}

int main() {
    cin >> n >> m;
    adj.resize(n); dist.resize(n, INF);
    
    for(int i = 0; i < m; i++) {
        int u, v, e;
        cin >> u >> v >> e;
        adj[u - 1].push_back(vertex(v - 1, e));
    }
    cin >> s >> e;
    s -= 1; e -= 1;
    Dijkstra();
    return 0;
}
