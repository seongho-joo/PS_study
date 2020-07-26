//
//  2566.cpp
//  test
//
//  Created by 주성호 on 2020/07/26.
//  Copyright © 2020 주성호. All rights reserved.
//
//  https://www.acmicpc.net/problem/2566
//  BOJ2566 최댓값 : 구현

#include <iostream>
using namespace std;

typedef pair<int, int> pii;

int main() {
    int ans = 0, a;
    pii p;
    for(int i = 0; i < 9; i++)
        for(int j = 0; j < 9; j++) {
            cin >> a;
            if(ans < a) {
                p = make_pair(i + 1, j + 1);
                ans = a;
            }
        }
    cout << ans << "\n" << p.first << " " << p.second << "\n";
    
    return 0;
}
