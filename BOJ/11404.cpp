//
//  11404.cpp
//  test
//
//  Created by 주성호 on 2020/09/24.
//  Copyright © 2020 주성호. All rights reserved.
//
//  https://www.acmicpc.net/problem/11404
//  BOJ11404 플로이드 : 그래프 이론, 플로이드-와샬

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int INF = 987654321;
vector<vector<int> > dist;
int n, m;

void floyd_warshall() {
    for(int k = 0; k < n; k++) {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
}

int main() {
    cin >> n >> m;
    dist.resize(n, vector<int>(n, INF));
    
    for(int i = 0; i < n; i++) dist[i][i] = 0;
    
    for(int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        dist[a - 1][b - 1] = min(dist[a - 1][b - 1], c);
    }
    
    floyd_warshall();
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(dist[i][j] == INF) cout << 0 << ' ';
            else cout << dist[i][j] << ' ';
        }
        cout << '\n';
    }
    
    return 0;
}
