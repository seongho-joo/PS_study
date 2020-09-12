//
//  2914.cpp
//  test
//
//  Created by 주성호 on 2020/09/12.
//  Copyright © 2020 주성호. All rights reserved.
//
//  https://www.acmicpc.net/problem/2914
//  BOJ2914 저작권 : 수학, 구현, 사칙연산

#include <iostream>
using namespace std;

int main() {
    int n, avg;
    cin >> n >> avg;
    
    int res = n * (avg - 1) + 1;
    
    cout << res << "\n";
    
    return 0;
}
