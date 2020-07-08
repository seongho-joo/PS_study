//
//  5576.cpp
//  OnlineJudge
//
//  Created by 주성호 on 2020/05/21.
//  Copyright © 2020 주성호. All rights reserved.
//
//  https://www.acmicpc.net/problem/5576 콘테스트

#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int a[10], b[10];
    int sumA = 0, sumB = 0;
    
    for(int i = 0; i < 10; i++) cin >> a[i];
    for(int i = 0; i < 10; i++) cin >> b[i];
    
    sort(a, a + 10);
    sort(b, b + 10);
    for(int i = 9; i >= 7; i--) sumA += a[i];
    for(int i = 9; i >= 7; i--) sumB += b[i];
    cout << sumA << " " << sumB << "\n";
    return 0;
}
