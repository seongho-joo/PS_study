//
//  10833.cpp
//  OnlineJudge
//
//  Created by 주성호 on 2020/04/23.
//  Copyright © 2020 주성호. All rights reserved.
//
//  https://www.acmicpc.net/problem/10833
//  사과

#include <iostream>
using namespace std;

int N, ans = 0;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    int x, y;
    while(N--) {
        cin >> x >> y;
        ans += (y % x);
    }
    cout << ans << '\n';
    return 0;
}

