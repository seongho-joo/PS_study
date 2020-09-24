//
//  2458.cpp
//  test
//
//  Created by 주성호 on 2020/09/24.
//  Copyright © 2020 주성호. All rights reserved.
//
//  https://www.acmicpc.net/problem/2458
//  BOJ2458 키 순서 : 그래프 이론, 그래프 탐색, 깊이 우선 탐색, 플로이드–와샬

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int> > list;
int n, m;

int main() {
    cin >> n >> m;
    list.resize(n, vector<int>(n, 0));
    
    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        list[u - 1][v - 1] = 1;
    }
    // 플로이드-와샬 알고리즘
    for(int k = 0; k < n; k++) {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                // 이어져있는 노드 연결
                if(list[i][k] == 1 && list[k][j] == 1)
                    list[i][j] = 1;
            }
        }
    }
    
    int res = 0;
    for(int i = 0; i < n; i++) {
        bool flag = false;
        for(int j = 0; j < n; j++) {
            if(i == j) continue;
            // 하나라도 연결이 안 되어있을 경우 키 순서는 알 수 없음
            if(list[i][j] == 0 && list[j][i] == 0) {
                flag = true;
                break;
            }
        }
        if(!flag) res += 1;
    }
    
    cout << res << "\n";
 
    return 0;
}
