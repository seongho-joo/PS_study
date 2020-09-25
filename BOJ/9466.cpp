//
//  9466.cpp
//  PS_Study
//
//  Created by 주성호 on 2020/09/25.
//  Copyright © 2020 주성호. All rights reserved.
//
//  https://www.acmicpc.net/problem/9466
//  BOJ9466 텀 프로젝트 : 그래프 이론, 그래프 탐색, 깊이 우선 탐색

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int MAX = 100000;
int arr[MAX];
bool visited[MAX], finished[MAX];

int T, N, cnt = 0;

void dfs(int cur) {
    visited[cur] = true;
    int next = arr[cur];

    if(visited[next]) {
        if(!finished[next]) {
            for(int i = next; i != cur; i = arr[i]) {
                cnt += 1;
            }
            // 자기 자신
            cnt += 1;
        }
    } else {
        dfs(next);
    }
    
    finished[cur] = true;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> T;
    
    while(T--) {
        cin >> N;
        // 배열 초기화
        fill(visited, visited + N, false);
        fill(finished, finished + N, false);
        fill(arr, arr + N, 0);
        
        for(int i = 0; i < N; i++) {
            cin >> arr[i];
            arr[i] -= 1;
        }
        
        cnt = 0;
        
        for(int i = 0; i < N; i++) {
            if(!visited[i]) dfs(i);
        }
        
        cout << N - cnt << "\n";
    }
    
    return 0;
}
