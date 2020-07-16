//
//  5046.cpp
//  test
//
//  Created by 주성호 on 2020/07/16.
//  Copyright © 2020 주성호. All rights reserved.
//
//  https://www.acmicpc.net/problem/5046
//  BOJ5046 전국 대학생 프로그래밍 대회 동아리 연합 : 구현

#include <iostream>
#include <algorithm>
using namespace std;

int n, b, h, w, p, a, min_cost = 987654321;

int main() {
    cin >> n >> b >> h >> w;
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    while(h--) {
        cin >> p;
        for(int i = 0; i < w; i++) {
            cin >> a;
            if(a >= n) {
                min_cost = min(min_cost, n * p);
            }
        }
    }
    if(min_cost > b) cout << "stay home\n";
    else cout << min_cost << "\n";
    return 0;
}
