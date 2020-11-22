//
//  1550.cpp
//  test
//
//  Created by 주성호 on 2020/11/22.
//  Copyright © 2020 주성호. All rights reserved.
//
//  https://www.acmicpc.net/problem/1550
//  BOJ1550 16진수 : 수학, 구현

#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>

using namespace std;

int main() {
    string inp;
    cin >> inp;
    
    reverse(inp.begin(), inp.end());
    
    int res = 0;
    
    for (int i = 0; i < inp.size(); i++) {
        int num;
        switch (inp[i]) {
            case 'A':
                num = 10; break;
            case 'B':
                num = 11; break;
            case 'C':
                num = 12; break;
            case 'D':
                num = 13; break;
            case 'E':
                num = 14; break;
            case 'F':
                num = 15; break;
            default:
                num = inp[i] - '0';
                break;
        }
        res += num * pow(16, i);
    }
    
    cout << res << "\n";
    
    return 0;
}
