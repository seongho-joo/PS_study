//
//  11689.cpp
//  OnlineJudge
//
//  Created by 주성호 on 2020/06/09.
//  Copyright © 2020 주성호. All rights reserved.
//
//  https://www.acmicpc.net/problem/11689 GCD(n, k) = 1

#include <iostream>
#include <algorithm>
using namespace std;

typedef long long lint;
lint gcd(lint a, lint b) {
    return (b == 0 ? a : gcd(b, a % b));
}

int main() {
    lint n, cnt = 0;
    cin >> n;
    if(n == 1) cnt = 1;
    else {
        for(lint i = 1; i < n; i++)
            if(gcd(n, i) == 1) cnt += 1;
    }
    cout << cnt << "\n";
    return 0;
}
