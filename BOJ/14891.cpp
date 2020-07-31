//
//  14891.cpp
//  test
//
//  Created by 주성호 on 2020/07/31.
//  Copyright © 2020 주성호. All rights reserved.
//
//  https://www.acmicpc.net/problem/14891
//  BOJ14891 톱니바퀴 : 시뮬레이션

#include <algorithm>
#include <iostream>
#include <deque>
using namespace std;

deque<char> cogwheel[4];
int K, n, dircetion;
// 1 : 시계
void clockwise(int idx) {
    cogwheel[idx].push_front(cogwheel[idx].back());
    cogwheel[idx].pop_back();
}
// -1 : 반시계
void counterclockwise(int idx) {
    cogwheel[idx].push_back(cogwheel[idx].front());
    cogwheel[idx].pop_front();
}

void solve() {
    // idx : 2 오른쪽에 맞물리는 극
    // idx : 6 왼쪽에 맞물리는 극
    pair<int, bool> turn[4];
    fill(turn, turn + 4, make_pair(0, false));
    turn[n] = make_pair(dircetion, true);
    int next = n + 1 , cur = n, pre = n - 1;
    int cur_direction = dircetion;
    int next_direction;
    bool isTurn = true;
    // 오른쪽 톱니바퀴들 회전하는지 확인
    while(true) {
        if(next > 3 || !isTurn) break;
        isTurn = false;
        if(cogwheel[cur][2] != cogwheel[next][6]) {
            next_direction = cur_direction == 1 ? -1 : 1;
            turn[next] = make_pair(next_direction, true);
            isTurn = true;
            cur = next;
            next += 1;
            cur_direction = next_direction;
        }
    }
    // 왼쪽 톱니바퀴들 회전하는지 확인
    cur = n;
    cur_direction = dircetion;
    isTurn = true;
    while(true) {
        if(pre < 0 || !isTurn) break;
        isTurn = false;
        if(cogwheel[pre][2] != cogwheel[cur][6]) {
            next_direction = cur_direction == 1 ? -1 : 1;
            turn[pre] = make_pair(next_direction, true);
            isTurn = true;
            cur = pre;
            pre -= 1;
            cur_direction = next_direction;
        }
    }
    
    for(int i = 0; i < 4; i++) {
        if(turn[i].second) {
            if(turn[i].first == 1)
                clockwise(i);
            else
                counterclockwise(i);
        }
    }
}

int main() {
    for(int i = 0; i < 4; i++)
        for(int j = 0; j < 8; j++) {
            char n;
            cin >> n;
            cogwheel[i].push_back(n);
        }
    cin >> K;
    while(K--) {
        cin >> n >> dircetion;
        n -= 1;
        solve();
    }
    int result = 0;
    for(int i = 0; i < 4; i++) {
        if(cogwheel[i].front() == '1') {
            switch (i) {
                case 0:
                    result += 1;
                    break;
                case 1:
                    result += 2;
                    break;
                case 2:
                    result += 4;
                    break;
                case 3:
                    result += 8;
                    break;
            }
        }
    }
    cout << result << "\n";
    return 0;
}
