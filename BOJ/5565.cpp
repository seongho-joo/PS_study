//
//  5565.cpp
//  OnlineJudge
//
//  Created by 주성호 on 2020/04/24.
//  Copyright © 2020 주성호. All rights reserved.
//
//  https://www.acmicpc.net/problem/5565 : 영수증

#include <iostream>
using namespace std;

int main() {
    int ans, num;
    cin >> ans;
    for(int i = 0; i < 9; i++) {
        cin >> num;
        ans -= num;
    }
    cout << ans << "\n";
    return 0;
}
