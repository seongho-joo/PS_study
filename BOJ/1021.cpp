//
//  1021.cpp
//  test
//
//  Created by 주성호 on 2020/07/30.
//  Copyright © 2020 주성호. All rights reserved.
//
//  https://www.acmicpc.net/problem/1021
//  BOJ1021 회전하는 큐 : 시뮬레이션

#include <iostream>
#include <deque>
using namespace std;

int N, M, cnt = 0;
deque<int> deq;

int main() {
    cin >> N >> M;
    for(int i = 1; i <= N; i++) deq.push_back(i);
    int n;
    while(M--) {
        cin >> n;
        int idx = 0;
        for(int i = 0; i < (int)deq.size(); i++)
            if(deq[i] == n) {
                idx = i; break;
            }
        if(idx < deq.size() - idx) {
            while(true) {
                if(n == deq.front()) {
                    deq.pop_front();
                    break;
                }
                cnt += 1;
                deq.push_back(deq.front());
                deq.pop_front();
            }
        } else {
            while(true) {
                if(n == deq.front()) {
                    deq.pop_front();
                    break;
                }
                cnt += 1;
                deq.push_front(deq.back());
                deq.pop_back();
            }
        }
    }
    cout << cnt << "\n";
    return 0;
}
