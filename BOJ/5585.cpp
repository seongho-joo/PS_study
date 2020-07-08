//
//  5585.cpp
//  OnlineJudge
//
//  Created by 주성호 on 2020/06/30.
//  Copyright © 2020 주성호. All rights reserved.
//
//  https://www.acmicpc.net/problem/5585 거스름돈

#include <iostream>
using namespace std;

int main() {
    int cur = 1000, n, ans = 0;
    cin >> n;
    cur -= n;
    
    while(cur != 0) {
        if(cur >= 500) {
            ans += 1;
            cur -= 500;
        }
        else if(cur >= 100) {
            ans += 1;
            cur -= 100;
        }
        else if(cur >= 50) {
            ans += 1;
            cur -= 50;
        }
        else if(cur >= 10) {
            ans += 1;
            cur -= 10;
        }
        else if(cur >= 5) {
            ans += 1;
            cur -= 5;
        }
        else {
            ans += 1;
            cur -= 1;
        }
    }
    cout << ans << "\n";
    
    return 0;
}
