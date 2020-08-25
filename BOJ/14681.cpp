//
//  14681.cpp
//  test
//
//  Created by 주성호 on 2020/08/25.
//  Copyright © 2020 주성호. All rights reserved.
//
//  https://www.acmicpc.net/problem/14681
//  BOJ14681 사분면 고르기 : 구현, 기하학

#include <iostream>
using namespace std;

int main() {
    int x, y, res = 0;
    cin >> x >> y;
    
    if(x > 0 && y > 0) res = 1;
    else if(x < 0 && y > 0) res = 2;
    else if(x < 0 && y < 0) res = 3;
    else res = 4;
    
    cout << res << "\n";
    
    return 0;
}
