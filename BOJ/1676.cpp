//
//  1676.cpp
//  OnlineJudge
//
//  Created by 주성호 on 2020/06/15.
//  Copyright © 2020 주성호. All rights reserved.
//
//  https://www.acmicpc.net/problem/1676 팩토리얼 0의 개수

#include <iostream>
#include <string>
using namespace std;

int solve(int n) {
    if(n == 0) return 0;
    int cnt = 0;
    for(int i = 1; i <= n; i++) {
        if(i % 5 == 0) cnt += 1;
        if(i % 25 == 0) cnt += 1;
        if(i % 125 == 0) cnt += 1;
    }
    return cnt;
}

int main() {
    int n;
    cin >> n;
    cout << solve(n) << "\n";
    return 0;
}
