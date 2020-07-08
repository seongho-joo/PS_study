//
//  5554.cpp
//  OnlineJudge
//
//  Created by 주성호 on 2020/07/02.
//  Copyright © 2020 주성호. All rights reserved.
//
//  https://www.acmicpc.net/problem/5554 심부름 가는 길

#include <iostream>
using namespace std;

int main() {
    int a, b, c, d, ans = 0;;
    cin >> a >> b >> c >> d;
    
    ans = a + b + c + d;
    
    int x = ans / 60;
    int y = ans % 60;
    
    cout << x << "\n" << y << "\n";
    
    return 0;
}
