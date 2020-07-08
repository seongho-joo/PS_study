//
//  1748.cpp
//  OnlineJudge
//
//  Created by 주성호 on 2020/07/01.
//  Copyright © 2020 주성호. All rights reserved.
//
//  https://www.acmicpc.net/problem/1748 수 이어 쓰기 1

#include <iostream>
#include <string>
using namespace std;

int main() {
    int n, res = 0;
    cin >> n;
    
    for(int i = 1; i <= n; i *= 10)
        res += n - i + 1;
    
    cout << res << "\n";
    
    return 0;
}
