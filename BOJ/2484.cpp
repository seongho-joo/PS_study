//
//  2484.cpp
//  test
//
//  Created by 주성호 on 2020/07/25.
//  Copyright © 2020 주성호. All rights reserved.
//
//  https://www.acmicpc.net/problem/2484
//  BOJ2484 주사위 네개 : 구현, 선형대수학, 수학

#include <iostream>
#include <algorithm>
using namespace std;

int ans = 0, N, dice, p;
int cnt[7];

int main() {
    cin >> N;
    
    for(int i = 0; i < N; i++) {
        int maxD = 0;
        for(int j = 0; j < 7; j++) cnt[j] = 0;
        for(int j = 0; j < 4; j++) {
            cin >> dice;
            maxD = max(maxD, dice);
            cnt[dice] += 1;
        }
        p = 0;
        for(int j = 1; j < 7; j++) {
            if(cnt[j] == 4) p = 50000 + j * 5000;
            else if(cnt[j] == 3) p = 10000 + j * 1000;
            else if(cnt[j] == 2) {
                for(int k = 1; k < 7; k++) {
                    if(j != k && cnt[k] == 2) p = 2000 + j * 500 + k * 500;
                }
                if(p == 0) p = 1000 +  j * 100;
            }
        }
        if(p == 0) p = maxD * 100;
        ans = max(ans, p);
    }
    
    cout << ans << "\n";

    return 0;
}
