//
//  2033.cpp
//  OnlineJudge
//
//  Created by 주성호 on 2020/07/07.
//  Copyright © 2020 주성호. All rights reserved.
//
//  https://www.acmicpc.net/problem/2033 반올림

#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double n;
    int m = 10;
    cin >> n;
    
    while(n > m) {
        n /= m;
        n = round(n) * m;
        m *= 10;
    }
    
    cout << (int)n << "\n";
    
    return 0;
}
