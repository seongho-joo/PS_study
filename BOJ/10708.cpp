//
//  10708.cpp
//  test
//
//  Created by 주성호 on 2020/07/13.
//  Copyright © 2020 주성호. All rights reserved.
//
//  https://www.acmicpc.net/problem/10708
//  BOJ10708 크리스마스 파티 : 구현

#include <iostream>
#include <vector>
using namespace std;

int N, M; // 친구들 수, 게임 횟수
vector<int> target, score;

void solve() {
    for(int i = 0; i < M; i++) {
        int cnt = 0;
        for(int j = 0; j < N; j++) {
            int game;
            cin >> game;
            if(target[i] == game) score[j] += 1;
            else cnt += 1;
        }
        score[target[i] - 1] += cnt;
    }
    
    for(int i : score) cout << i << "\n";
}

int main() {
    cin >> N >> M;
    target.resize(M);
    score.resize(N);
    
    for(int i = 0; i < M; i++) cin >> target[i];
    solve();
    return 0;
}
