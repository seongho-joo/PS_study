//
//  5014.cpp
//  test
//
//  Created by 주성호 on 2020/09/25.
//  Copyright © 2020 주성호. All rights reserved.
//
//  https://www.acmicpc.net/problem/5014
//  BOJ5014 스타트링크 : 그래프 이론, 그래프 탐색, 너비 우선 탐색

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef pair<int, int> pii;
vector<int> dist;
vector<bool> v;
int f, s, g, u, d;

int bfs() {
    int ret = -1;
    queue<pii> Q;
    Q.push({s, 0});
    v[s] = true;
    while(!Q.empty()) {
        int cur = Q.front().first;
        int cnt = Q.front().second;
        Q.pop();

        if(cur == g) {
            ret = cnt;
            break;
        }

        if(cur + u <= f && !v[cur + u]) {
            Q.push({cur + u, cnt + 1});
            v[cur + u] = true;
        }

        if(cur - d >= 1 && !v[cur - d]) {
            Q.push({cur - d, cnt + 1});
            v[cur - d] = true;
        }
    }
    return ret;
}

int main () {
    cin >> f >> s >> g >> u >> d;
    v.resize(f + 1, false); dist.resize(f + 1, 0);

    int res = bfs();

    if(res == -1) {
        cout << "use the stairs\n";
    } else {
        cout << res << "\n";
    }

    return 0;
}
