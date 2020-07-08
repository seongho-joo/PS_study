//
//  1717.cpp
//  OnlineJudge
//
//  Created by 주성호 on 2020/06/15.
//  Copyright © 2020 주성호. All rights reserved.
//
//  https://www.acmicpc.net/problem/1717 집합의 표현

#include <iostream>
#include <vector>
using namespace std;

vector<int> p;

int find(int n) {
    if(p[n] == n) return n;
    p[n] = find(p[n]);
    return p[n];
}

void Union(int a, int b) {
    a = find(a);
    b = find(b);
    if(a == b) return;
    p[a] = b;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, m;
    cin >> n >> m;
    p.resize(n + 1);
    for(int i = 1; i < n + 1; i++) p[i] = i;
    
    for(int i = 0; i < m; i++) {
        int q, a, b;
        cin >> q >> a >> b;
        if(q == 1) {
            int a_ = find(a);
            int b_ = find(b);
            if(a_ == b_) cout << "YES\n";
            else cout << "NO\n";
        }
        else Union(a, b);
    }
    return 0;
}
