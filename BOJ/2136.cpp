//
//  2136.cpp
//  test
//
//  Created by 주성호 on 2020/07/23.
//  Copyright © 2020 주성호. All rights reserved.
//
//  https://www.acmicpc.net/problem/2136
//  BOJ2136 개미 : 구현

#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

typedef pair<int, int> pii;
int N, L, left_dist, right_dist, cnt;
vector<int> a;
vector<pii> res;

bool compare(const pii& a, const pii& b) {
    return a.second < b.second;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N >> L;
    a.resize(N); res.resize(N);
    
    for(int i = 0; i < N; i++) cin >> a[i];
    for(int i = 0; i < N; i++) {
        if(a[i] < 0) {
            cnt += 1;
            left_dist = max(abs(a[i]), left_dist);
        } else {
            right_dist = max(L - a[i], right_dist);
        }
        res[i] = make_pair(i + 1, abs(a[i]));
    }
    sort(res.begin(), res.end(), compare);
    
    if(left_dist > right_dist) cout << res[cnt - 1].first << " " << left_dist << "\n";
    else cout << res[cnt].first << " " << right_dist << "\n";
    
    return 0;
}
