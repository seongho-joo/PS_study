//
//  1934.cpp
//  OnlineJudge
//
//  Created by 주성호 on 2020/06/30.
//  Copyright © 2020 주성호. All rights reserved.
//
//  https://www.acmicpc.net/problem/1934 최소공배수

#include <iostream>
#include <algorithm>
using namespace std;

int gcd(int a, int b) {
    return a % b ? gcd(b, a % b) : b;
}

int main() {
    int T;
    cin >> T;
    while(T--) {
        int a, b;
        cin >> a >> b;
        if(a < b) swap(a, b);
        cout << a * b / gcd(a, b) << "\n";
    }
    return 0;
}
