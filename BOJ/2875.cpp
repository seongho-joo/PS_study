//
//  2875.cpp
//  test
//
//  Created by 주성호 on 2020/09/06.
//  Copyright © 2020 주성호. All rights reserved.
//
//  https://www.acmicpc.net/problem/2875
//  BOJ2875 대회 or 인턴 : 수학, 구현

#include <iostream>
using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    int limit = n + m - k, team = 1;
    
    while(true) {
        int tempW = team * 2;
        int tempM = team;
        if(tempM + tempW > limit || tempW > n || tempM > m) break;
        team += 1;
    }
    
    cout << team - 1 << "\n";
    return 0;
}
