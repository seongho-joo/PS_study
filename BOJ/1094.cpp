//
//  1094.cpp
//  test
//
//  Created by 주성호 on 2020/07/28.
//  Copyright © 2020 주성호. All rights reserved.
//
//  https://www.acmicpc.net/problem/1094
//  BOJ1094 막대기 : 수학, 시뮬레이션

#include <iostream>
#include <algorithm>
using namespace std;

int X, origin = 64;
int bar[7];

int main() {
    cin >> X;
    bar[0] = origin;
    
    for(int i = 1; i < 7; i++) {
        if(origin == 1) break;
        origin /= 2;
        bar[i] = origin;
    }
    bool flag = false;
    int sum = 0, cnt = 0;
    
    for(int i = 0; i < 7; i++) {
        if(bar[i] == X) {
            cnt = 1;
            flag = true;
            break;
        }
    }
    
    if(!flag) {
        for(int i = 0; i < 7; i++) {
            if(X > sum) {
                cnt += 1;
                sum += bar[i];
                if(sum == X) break;
                else if(sum > X) {
                    sum -= bar[i];
                    cnt -= 1;
                }
            }
        }
    }
    cout << cnt << "\n";
    return 0;
}
