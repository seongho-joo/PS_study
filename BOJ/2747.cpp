//
//  10830.cpp
//  OnlineJudge
//
//  Created by 주성호 on 2020/06/15.
//  Copyright © 2020 주성호. All rights reserved.
//
//  https://www.acmicpc.net/problem/2747 피보나치 수

#include <iostream>
using namespace std;

typedef long long lint;
lint dp[46];

int main() {
    int n;
    dp[1] = 1;
    dp[2] = 1;
    for(int i = 3; i < 46; i++)
        dp[i] = dp[i - 1] + dp[i - 2];
    
    cin >> n;
    cout << dp[n] << "\n";
    return 0;
}
