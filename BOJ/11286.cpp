//
//  11286.cpp
//  test
//
//  Created by 주성호 on 2020/10/17.
//  Copyright © 2020 주성호. All rights reserved.
//
//  https://www.acmicpc.net/problem/11286
//  BOJ11286 절댓값 힙 : 구현, 자료 구조, 우선순위 큐

#include <iostream>
#include <algorithm>
#include <cmath>
#include <queue>

using namespace std;

typedef pair<int, int> pii;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N, num;
    cin >> N;
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    while (N--) {
        cin >> num;
        if (num != 0) {
            pq.push(make_pair(abs(num), num));
        } else {
            if (pq.empty()) {
                cout << "0\n";
            } else {
                cout << pq.top().second << "\n";
                pq.pop();
            }
        }
    }
    
    return 0;
}
