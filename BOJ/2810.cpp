//
//  2810.cpp
//  OnlineJudge
//
//  Created by 주성호 on 2020/07/07.
//  Copyright © 2020 주성호. All rights reserved.
//
//  https://www.acmicpc.net/problem/2810 컵홀더

#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    string seat;
    int n, res = 1, num = 0;
    cin >> n >> seat;
    for(int i = 0; i < n; i++) {
        if(seat[i] == 'L') {
            i += 1;
            num += 1;
        }
        num += 1;
        res += 1;
    }
    
    if(num < res) res = num;
    
    cout << res << "\n";
    
    return 0;
}
