//
//  5618.cpp
//  OnlineJudge
//
//  Created by 주성호 on 2020/06/30.
//  Copyright © 2020 주성호. All rights reserved.
//
//  https://www.acmicpc.net/problem/5618 공약수

#include <iostream>
#include <algorithm>
#include <set>
#include <cmath>
using namespace std;
set<int> cd;

int gcd(int a, int b) {
    if(a < b) swap(a, b);
    return a % b ? gcd(b, a % b) : b;
}

void divisor(int n) {
    for(int i = 1; i <= n; i++)
        if(n % i == 0) cd.insert(i);
}

int main() {
    int n, num[3];
    cin >> n;
    
    for(int i = 0; i < n; i++) cin >> num[i];
    int ans = 0;
    if(n != 2)
        ans = gcd(gcd(num[0], num[1]), num[2]);
    else ans = gcd(num[0], num[1]);
    
    divisor(ans);
    
    for(auto i : cd) cout << i << "\n";
    
    return 0;
}
