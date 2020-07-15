//
//  2790.cpp
//  test
//
//  Created by 주성호 on 2020/07/15.
//  Copyright © 2020 주성호. All rights reserved.
//
//  https://www.acmicpc.net/problem/2790
//  BOJ2790 F7 : 수학, 구현

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    vector<int> driver;
    int N;
    
    cin >> N;
    driver.resize(N);
    
    for(int i = 0; i < N; i++) cin >> driver[i];
    sort(driver.begin(), driver.end(), greater<int>());
    
    int max_s = driver[0] + 1;
    int ans = 1;
    
    for(int i = 1; i < N; i++) {
        if(max_s <= driver[i] + N) {
            max_s = max(max_s, driver[i] + i + 1);
            ans += 1;
        }
    }
    
    cout << ans << "\n";
    
    return 0;
}
