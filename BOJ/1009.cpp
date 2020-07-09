//
//  1009.cpp
//  test
//
//  Created by 주성호 on 2020/07/09.
//  Copyright © 2020 주성호. All rights reserved.
//
//  https://www.acmicpc.net/problem/1009
//  BOJ1009 분산처리 : 구현

#include <iostream>
#include <cmath>
using namespace std;

int cache[10] = {0, 0, 4, 4, 2, 0, 0, 4, 4, 2};

int main() {
    int T;
    cin >> T;
    
    while(T--) {
        int a, b, res;
        cin >> a >> b;
        a %= 10;
        if(a == 0) res = 10;
        else if(a == 1) res = 1;
        else if(a == 5) res = 5;
        else if(a == 6) res = 6;
        else {
            int p = b % cache[a];
            if (p == 0) p = cache[a];
            res = (int)pow(a, p) % 10;
        }
        cout << res << "\n";
    }
    return 0;
}
