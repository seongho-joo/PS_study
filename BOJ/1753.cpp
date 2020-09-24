//
//  1753.cpp
//  PS_Study
//
//  Created by 주성호 on 2020/09/24.
//  Copyright © 2020 주성호. All rights reserved.
//
//  https://www.acmicpc.net/problem/1753
//  BOJ1753 최단경로 : 그래프 이론, 다익스트라

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef pair<int, int> pii;
struct Vertex {
    int v, e;
    Vertex() : v(0), e(0) {}
    Vertex(int v, int e) : v(v), e(e) {}
};
const int INF = 1000000000;
vector<vector<Vertex> > adj;
vector<int> dist;
int V, E, s;

void Dijkstra() {
    priority_queue<pii, vector<pii>, greater<pii> > pq;
    vector<bool> v(V, false);
    pq.push({0, s});
    
    while(!pq.empty()) {
        int cur;
        do {
            cur = pq.top().second;
            pq.pop();
        }
        while(!pq.empty() && v[cur]);
        
        if(v[cur]) break;
        
        v[cur] = true;
        
        for(int i = 0; i < adj[cur].size(); i++) {
            int next = adj[cur][i].v; // 다음 정점
            int d = adj[cur][i].e; // cur -> next의 가중치
            // next cost보다 작을경우 dist 값 갱신 pq 삽입
            if(dist[next] > dist[cur] + d) {
                dist[next] = dist[cur] + d;
                pq.push({dist[next], next});
            }
        }
    }
    
    for(int i : dist) {
        if(i == INF) cout << "INF\n";
        else cout << i << "\n";
    }
}

int main() {
    cin >> V >> E >> s;
    adj.resize(V);
    dist.resize(V, INF);
    s -= 1;
    dist[s] = 0;
    
    for(int i = 0; i < E; i++) {
        int u, v, e;
        cin >> u >> v >> e;
        adj[u - 1].push_back(Vertex(v - 1, e));
    }
    
    Dijkstra();
    
    return 0;
}
