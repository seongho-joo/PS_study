//
//  2038.cpp
//  test
//
//  Created by 주성호 on 2020/07/24.
//  Copyright © 2020 주성호. All rights reserved.
//
//  https://www.acmicpc.net/problem/2038
//  BOJ2038 골롱 수열 : 수학, 구현, 동적계획법

#include <iostream>
#include <map>
using namespace std;

typedef long long lint;
map<lint, lint> seq;

int main() {
    lint sum = 0;
    int n;
    cin >> n;
    
    if(n == 1) cout << 1 << "\n";
    else {
        seq[1] = 1;
        sum += 1;
        for(int i = 1; i <= n; i++) {
            seq[i + 1] = 1 + seq[i + 1 - seq[seq[i]]];
            sum += seq[i + 1];
            if(sum >= n) {
                cout << i + 1 << "\n";
                break;
            }
        }
    }
    return 0;
}
