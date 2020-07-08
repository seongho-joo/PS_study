//
//  10156.cpp
//  OnlineJudge
//
//  Created by 주성호 on 2020/04/23.
//  Copyright © 2020 주성호. All rights reserved.
//
//  https://www.acmicpc.net/problem/10156 과자

#include <iostream>
using namespace std;

int main() {
    int price, num, cur, ans;
    cin >> price >> num >> cur;
    ans = price * num -  cur;
    cout << (ans < 0 ? 0 : ans) << '\n';
    return 0;
}
