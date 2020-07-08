//
//  5532.cpp
//  OnlineJudge
//
//  Created by 주성호 on 2020/07/02.
//  Copyright © 2020 주성호. All rights reserved.
//
//  https://www.acmicpc.net/problem/5532 방학 숙제

#include <iostream>
using namespace std;

int main() {
    int L, A, B, C, D;
    cin >> L >> A >> B >> C >> D;
    
    int korean = (A % C ? A / C + 1 : A / C);
    int math = (B % D ? B / D + 1 : B / D);
    
    cout << L - (korean < math ? math : korean) << "\n";
    
    return 0;
}
