//
//  5575.cpp
//  OnlineJudge
//
//  Created by 주성호 on 2020/05/21.
//  Copyright © 2020 주성호. All rights reserved.
//
//  https://www.acmicpc.net/problem/5575 타임 카드

#include <iostream>
using namespace std;

struct Time {
    int h, m, s;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    for(int i = 0; i < 3; i++) {
        Time t1, t2, ans;
        cin >> t1.h >> t1.m >> t1.s;
        cin >> t2.h >> t2.m >> t2.s;
        
        ans.s = t2.s - t1.s;
        ans.m = t2.m - t1.m;
        ans.h = t2.h - t1.h;
        
        if(ans.s < 0) {
            ans.s += 60;
            ans.m -= 1;
        }
        
        if(ans.m < 0) {
            ans.m += 60;
            ans.h -= 1;
        }
        
        cout << ans.h << " " << ans.m << " " << ans.s << "\n";
    }
    
    return 0;
}
