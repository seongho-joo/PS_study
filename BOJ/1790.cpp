//
//  1790.cpp
//  test
//
//  Created by 주성호 on 2020/07/14.
//  Copyright © 2020 주성호. All rights reserved.
//
//  https://www.acmicpc.net/problem/1790
//  BOJ1790 수 이어 쓰기 2 : 구현

#include <iostream>
#include <string>
using namespace std;

typedef long long lint;

lint n, k, calcK;

int main() {
    cin >> n >> k;
    calcK = k;
    
    lint numLength = 1, numCount = 9;
    lint result = 0, total = 0;
    
    while(calcK > numLength * numCount) {
        total += numCount;
        calcK -= numLength * numCount;
        numCount *= 10;
        numLength += 1;
    }
    
    total += (calcK - 1) / numLength + 1;
    int idx = (calcK - 1) % numLength;
    
    if (total > n) result = -1;
    else {
        string s = to_string(total);
        result = s[idx] - '0';
    }
    
    cout << result << "\n";
    
    return 0;
}
