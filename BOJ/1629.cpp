//
//  1629.cpp
//  OnlineJudge
//
//  Created by 주성호 on 2020/06/15.
//  Copyright © 2020 주성호. All rights reserved.
//
//  https://www.acmicpc.net/problem/1629 곱셈

#include <iostream>
using namespace std;

typedef long long lint;
int c;

lint pow(int a, int b) {
    if(b == 0) return 1;
    lint val = pow(a, b / 2);
    val = (val * val) % c;
    
    if(b % 2 == 0) return val;
    else return (val * a) % c;
}

int main() {
    int a, b;
    cin >> a >> b >> c;
    cout << pow(a, b) << "\n";
    return 0;
}
