//
//  5596.cpp
//  OnlineJudge
//
//  Created by 주성호 on 2020/05/30.
//  Copyright © 2020 주성호. All rights reserved.
//
//  https://www.acmicpc.net/problem/5596 시험 점수

#include <iostream>
using namespace std;

int main() {
    int S = 0, T = 0;
    int inp = 0;
    for(int i = 0; i < 4; i++) {
        cin >> inp;
        S += inp;
    }
    for(int i = 0; i < 4; i++) {
        cin >> inp;
        T += inp;
    }
    cout << (S >= T ? S : T) << "\n";
    return 0;
}
