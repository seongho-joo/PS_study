//
//  2523.cpp
//  test
//
//  Created by 주성호 on 2020/08/25.
//  Copyright © 2020 주성호. All rights reserved.
//
//  https://www.acmicpc.net/problem/2523
//  BOJ2523 별 찍기 - 13 : 구현

#include <iostream>
using namespace std;

int main () {
    int N;
    cin >> N;
    
    for(int i = 1; i < N * 2; i++) {
        if(i <= N) {
            for(int j = 0; j < i; j++) cout << "*";
        } else {
            for(int j = N; j > i - N; j--) cout << "*";
        }
        cout << "\n";
    }
    
    return 0;
}
