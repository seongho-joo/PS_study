//
//  1789.cpp
//  OnlineJudge
//
//  Created by 주성호 on 2020/07/02.
//  Copyright © 2020 주성호. All rights reserved.
//
//  https://www.acmicpc.net/problem/1789 수들의 합

#include <iostream>
using namespace std;

typedef long long lint;

int main() {
    lint s, n;
    cin >> s;
    
    for(lint i = 1;;i++) {
        if(s * 2 < i * i + i) {
            n = i - 1;
            break;
        }
    }
    
    cout << n << "\n";
    
    return 0;
}
