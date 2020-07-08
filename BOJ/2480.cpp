//
//  2480.cpp
//  OnlineJudge
//
//  Created by 주성호 on 2020/06/15.
//  Copyright © 2020 주성호. All rights reserved.
//
//  https://www.acmicpc.net/problem/2480 주사위 세개

#include <iostream>
#include <algorithm>
using namespace std;

int a, b, c;
int main() {
    cin >> a >> b >> c;
    int ans = 0;
    if(a == b && a == c && b == c) ans = 10000 + a * 1000;
    else if(a != b && a != c && c != b) {
        int Max = max(max(a, b), max (b, c));
        ans = Max * 100;
    }
    else {
        if(a == b) ans = 1000 + a * 100;
        else if (a == c) ans = 1000 + a * 100;
        else ans = 1000 + b * 100;
    }
    cout << ans << "\n";
    return 0;
}
