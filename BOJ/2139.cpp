//
//  2139.cpp
//  OnlineJudge
//
//  Created by 주성호 on 2020/06/11.
//  Copyright © 2020 주성호. All rights reserved.
//
//  https://www.acmicpc.net/problem/2193 이친수

#include <iostream>
using namespace std;

long long cache[91];

void Fibo() {
    for(int i = 4; i < 91; i++)
        cache[i] = cache[i - 1] + cache[i - 2];
}

int main() {
    cache[1] = 1;
    cache[2] = 1;
    cache[3] = 2;
    Fibo();
    int n;
    cin >> n;
    cout << cache[n] << "\n";
    return 0;
}
