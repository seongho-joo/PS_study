//
//  1475.cpp
//  test
//
//  Created by 주성호 on 2020/08/25.
//  Copyright © 2020 주성호. All rights reserved.
//
//  https://www.acmicpc.net/problem/1475
//  BOJ1475 방 번호 : 구현

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int numCount[10];

int main() {
    int res = 0;
    string num;
    cin >> num;
    
    for(int i = 0; i < num.length(); i++) numCount[num[i] - '0'] += 1;
    
    for(int i = 0; i < 10; i++)
        if(i != 6 && i != 9)
            res = max(res, numCount[i]);
    
    res = max(res, (numCount[6] + numCount[9] + 1) / 2);
    cout << res << "\n";
    
    return 0;
}
