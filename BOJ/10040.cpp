//
//  10040.cpp
//  test
//
//  Created by 주성호 on 2020/07/13.
//  Copyright © 2020 주성호. All rights reserved.
//
//  https://www.acmicpc.net/problem/10040
//  BOJ10040 투표 : 구현

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

typedef pair<int, int> pii;
int N, M, audit;
pii ans;
vector<int> cost, vote;

int funnyGame() {
    for(int i = 0; i < N; i++)
        if(audit >= cost[i]) return i;
    return 0;
}

int main() {
    cin >> N >> M;
    
    cost.resize(N);
    vote.resize(N);
    
    for(int i = 0; i < N; i++) cin >> cost[i];
    for(int i = 0; i < M; i++) {
        cin >> audit;
        vote[funnyGame()] += 1;
    }
    ans = make_pair(0, 0);
    for(int i = 0; i < N; i++) {
        if(ans.second < vote[i])
            ans = make_pair(i + 1, vote[i]);
    }
    
    cout << ans.first << "\n";
    
    return 0;
}
