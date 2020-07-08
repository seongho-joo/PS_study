//
//  1788.cpp
//  OnlineJudge
//
//  Created by 주성호 on 2020/07/02.
//  Copyright © 2020 주성호. All rights reserved.
//
//  https://www.acmicpc.net/problem/1788 피보나치 수의 확장

#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

typedef long long lint;
const int MOD = 1000000000;

vector<lint> dp;

int main() {
    int n;
    cin >> n;
    dp.resize(abs(n) + 1);
    dp[0] = 0;
    dp[1] = 1;
    int sign = 1;
    if(n == 0) sign = 0;
    for(int i = 2; i <= abs(n); i++)
        dp[i] = (dp[i - 1] + dp[i - 2]) % MOD;
    
    if(n < 0) {
        if(abs(n) % 2 == 0) sign = -1;
        else sign = 1;
    }
    
    cout << sign << "\n" << dp[abs(n)] % MOD << "\n";
    
    return 0;
}
