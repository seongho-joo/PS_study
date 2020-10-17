//
//  1697.cpp
//  test
//
//  Created by 주성호 on 2020/10/17.
//  Copyright © 2020 주성호. All rights reserved.
//
//  https://www.acmicpc.net/problem/1697
//  BOJ1697 숨바꼭질 : 그래프 이론, 그래프 탐색, 너비 우선 탐색

#include <iostream>
#include <queue>
#include <vector>

using namespace std;
typedef pair<int, int> pii;

const int MAX = 100001;
int N, K;
int dx[] = {-1, 1, 2};
bool visited[MAX] = {false, };

int main() {
    cin >> N >> K;
    
    queue<pii> Q;
    Q.push(make_pair(N, 0));
    visited[N] = true;
    int res = 0;
    while(!Q.empty()) {
        pii cur = Q.front(); Q.pop();
        if(cur.first == K) {
            res = cur.second;
            break;
        }
        for(int i = 0; i < 3; i++) {
            int nx = cur.first;
            if (i == 2) {
                nx *= 2;
            } else {
                nx += dx[i];
            }
            if(nx >= 0 && nx <= MAX) {
                if(!visited[nx]) {
                    visited[nx] = true;
                    Q.push(make_pair(nx, cur.second + 1));
                }
            }
        }
    }
    
    cout << res << "\n";
    
    return 0;
}
