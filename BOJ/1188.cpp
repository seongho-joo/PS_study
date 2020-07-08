//
//  1188.cpp
//  OnlineJudge
//
//  Created by 주성호 on 2020/07/07.
//  Copyright © 2020 주성호. All rights reserved.
//
//  https://www.acmicpc.net/problem/1188 음식 평론가

#include <iostream>
using namespace std;

int gcd(int a, int b) {
    return (a % b) ? gcd(b, a % b) : b;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, m;
    cin >> n >> m;
    
    cout << m - gcd(n, m) << "\n";
    
    return 0;
}
