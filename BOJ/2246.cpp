//
//  2246.cpp
//  test
//
//  Created by 주성호 on 2020/07/15.
//  Copyright © 2020 주성호. All rights reserved.
//
//  https://www.acmicpc.net/problem/2246
//  BOJ2246 콘도 선정 : 구현

#include <iostream>
#include <algorithm>
using namespace std;

typedef pair<int, int> pii;
int n, ans;
pii candidate[10001];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;

    
    for(int i = 0; i < n; i++) cin >> candidate[i].first >> candidate[i].second;
    sort(candidate, candidate + n);
    
    int min_p = 987654321;
    for(int i = 0; i < n; i++) {
        if(min_p > candidate[i].second) {
            ans += 1;
            min_p = candidate[i].second;
        }
    }
    
    cout << ans << "\n";
    return 0;
}
