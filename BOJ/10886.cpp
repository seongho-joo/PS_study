//
//  10886.cpp
//  OnlineJudge
//
//  Created by 주성호 on 2020/06/30.
//  Copyright © 2020 주성호. All rights reserved.
//
//  https://www.acmicpc.net/problem/10886 0 = not cute / 1 = cute

#include <iostream>
using namespace std;

int main() {
    int cute = 0, notCute = 0;
    int n;
    cin >> n;
    while(n--) {
        int a;
        cin >> a;
        a ? cute += 1 : notCute += 1;
    }
    cout << (cute < notCute ? "Junhee is not cute!" : "Junhee is cute!") << "\n";
    return 0;
}
