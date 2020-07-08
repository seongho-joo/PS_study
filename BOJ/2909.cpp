//
//  2909.cpp
//  OnlineJudge
//
//  Created by 주성호 on 2020/07/07.
//  Copyright © 2020 주성호. All rights reserved.
//
//  https://www.acmicpc.net/problem/2909 캔디 구매

#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int price, n, money = 1;
    cin >> price >> n;
    
    for(int i = 0; i < n; i++) money *= 10;
    double temp = (double)price / money;
    int res = round(temp) * money;
    
    cout << res << "\n";
    
    return 0;
}
