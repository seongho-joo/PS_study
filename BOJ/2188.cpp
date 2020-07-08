//
//  2188.cpp
//  OnlineJudge
//
//  Created by 주성호 on 2020/04/27.
//  Copyright © 2020 주성호. All rights reserved.
//
//  https://www.acmicpc.net/problem/2188 - 축사 배정

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

const int MAX = 200;
int N, M;
vector<int> A, B;
vector<vector<int> > near;
bool visited[MAX];

bool dfs(int a) {
    visited[a] = true;
    for(int i = 0; i < near[a].size(); i++) {
        int b = near[a][i];
        if(B[b] == -1 || !visited[B[b]] && dfs(B[b])) {
            A[a] = b;
            B[b] = a;
            return true;
        }
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    cin >> N >> M;
    A.resize(N, -1); B.resize(M, -1);
    near.resize(N);
    for(int i = 0; i < N; i++) {
        int s;
        cin >> s;
        for(int j = 0; j < s; j++) {
            int v;
            cin >> v;
            near[i].push_back(v - 1);
        }
    }
    int match = 0;
    for(int i = 0; i < N; i++) {
        if(A[i] == -1) {
            fill(visited, visited + N, false);
            if(dfs(i)) match += 1;
        }
    }
    cout << match << "\n";
    return 0;
}
