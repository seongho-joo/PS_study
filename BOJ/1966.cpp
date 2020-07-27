//
//  1966.cpp
//  test
//
//  Created by 주성호 on 2020/07/27.
//  Copyright © 2020 주성호. All rights reserved.
//
//  https://www.acmicpc.net/problem/1966
//  BOJ1966 프린터 큐 : 브루트 포스, 큐, 시물레이션

#include <iostream>
#include <queue>
using namespace std;
typedef pair<int, int> pii;

void solve(queue<pii>& q, priority_queue<int>& pq, int M) {
    int cnt = 0;
    while(!q.empty()) {
        pii p = q.front();
        q.pop();
        if(pq.top() == p.first) {
            cnt += 1;
            pq.pop();
            if(p.second == M) {
                cout << cnt << "\n";
                break;
            }
        } else q.push(p);
    }
}

int main() {
    int T, N, M, n;
    cin >> T;
    while(T--) {
        queue<pii> q;
        priority_queue<int> pq;
        cin >> N >> M;
        for(int i = 0; i < N; i++) {
            cin >> n;
            q.push(make_pair(n, i));
            pq.push(n);
        }
        solve(q, pq, M);
    }
    return 0;
}
