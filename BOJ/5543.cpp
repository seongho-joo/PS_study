//
//  5543.cpp
//  OnlineJudge
//
//  Created by 주성호 on 2020/05/21.
//  Copyright © 2020 주성호. All rights reserved.
//
//  https://www.acmicpc.net/problem/5543 상근날드

#include <iostream>
using namespace std;

int main() {
    int a, MIN = 987654321, sum = 0;
    for(int i = 0; i < 3; i++) {
        cin >> a;
        MIN = MIN < a ? MIN : a;
    }
    sum += MIN;
    MIN = 987654321;
    for(int i = 0; i < 2; i++) {
        cin >> a;
        MIN = MIN < a ? MIN : a;
    }
    sum += MIN;
    cout << sum - 50 << "\n";
    return 0;
}
