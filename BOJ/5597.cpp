//
//  5597.cpp
//  OnlineJudge
//
//  Created by 주성호 on 2020/05/30.
//  Copyright © 2020 주성호. All rights reserved.
//
//  https://www.acmicpc.net/problem/5597 과제 안 내신 분..?

#include <iostream>
using namespace std;

int main() {
    bool list[30] = {false, };
    int num;
    for(int i = 0; i < 28; i++) {
        cin >> num;
        list[num - 1] = true;
    }
    for(int i = 0; i < 30; i++)
        if(!list[i]) cout << i + 1 << "\n";
    
    return 0;
}
