//
//  5063.cpp
//  OnlineJudge
//
//  Created by 주성호 on 2020/07/02.
//  Copyright © 2020 주성호. All rights reserved.
//
//  https://www.acmicpc.net/problem/5063 TGN

#include <iostream>
#include <string>
using namespace std;

int main() {
    int r, e, c, T;
    string str[3] = {"advertise", "do not advertise", "does not matter"}, ans;
    cin >> T;
    
    while(T--) {
        cin >> r >> e >> c;
        
        if(r < e - c) ans = str[0];
        else if (r == e - c) ans = str[2];
        else ans = str[1];
        
        cout << ans << "\n";
    }
    
    return 0;
}
