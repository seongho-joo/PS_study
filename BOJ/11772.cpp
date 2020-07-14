//
//  11772.cpp
//  test
//
//  Created by 주성호 on 2020/07/14.
//  Copyright © 2020 주성호. All rights reserved.
//
//  https://www.acmicpc.net/problem/11772
//  BOJ11772 POT : 구현

#include <iostream>
#include <cmath>
using namespace std;

typedef long long lint;

int main() {
    int T;
    lint res = 0;
    cin >> T;
    
    while(T--) {
        int n, pot;
        cin >> n;
        pot = n % 10;
        n /= 10;
        res += pow(n, pot);
    }
    
    cout << res << "\n";
    return 0;
}
