//
//  10540.cpp
//  test
//
//  Created by 주성호 on 2020/07/24.
//  Copyright © 2020 주성호. All rights reserved.
//
//  https://www.acmicpc.net/problem/10540
//  BOJ10540 KLOPKA : 구현

#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int minX = 987654321, minY = 987654321, maxX = -1, maxY = -1;
    int n;
    cin >> n;
    
    while(n--) {
        int x, y;
        cin >> x >> y;
        
        minX = x < minX ? x : minX;
        minY = y < minY ? y : minY;
        maxX = x < maxX ? maxX : x;
        maxY = y < maxY ? maxY : y;
    }
    int res = (maxX - minX) < (maxY - minY) ? (maxY - minY) : (maxX - minX);
    cout << res * res << "\n";
    
    return 0;
}
