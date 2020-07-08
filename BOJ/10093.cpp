//
//  10093.cpp
//  OnlineJudge
//
//  Created by 주성호 on 2020/06/15.
//  Copyright © 2020 주성호. All rights reserved.
//
//  https://www.acmicpc.net/problem/10093 숫자

#include <algorithm>
#include <iostream>
using namespace std;

typedef unsigned long long ulint;

int main() {
    ulint a, b;
    cin >> a >> b;
    if(a == b) {
        cout << 0 << "\n";
    } else {
        if(a > b) swap(a, b);
        if(a + 1 == b) {
            cout << "0\n";
            return 0;
        }
        cout << b - a  - 1 << "\n";
        for(ulint i = a + 1; i < b; i++) cout << i << " ";
        cout << endl;
    }
    return 0;
}
