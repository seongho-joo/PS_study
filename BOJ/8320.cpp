//
//  8320.cpp
//  OnlineJudge
//
//  Created by 주성호 on 2020/06/30.
//  Copyright © 2020 주성호. All rights reserved.
//
//  https://www.acmicpc.net/problem/8320 직사각형을 만드는 방법

#include <iostream>
using namespace std;

int main() {
    int n, r = 0;
    cin >> n;
    
    for(int i = 1; i <= n; i++)
        for(int j = i; i * j <= n; j++) r += 1;
    
    cout << r << "\n";
    
    return 0;
}
