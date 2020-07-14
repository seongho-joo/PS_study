//
//  1756.cpp
//  test
//
//  Created by 주성호 on 2020/07/14.
//  Copyright © 2020 주성호. All rights reserved.
//
//  https://www.acmicpc.net/problem/1756
//  BOJ1756 피자 굽기 : 배열, 구현, 이분탐색, 시물레이션

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int D, N;
vector<int> oven;

int binary_search(int s, int e, int r) {
    if(e <= 0) return - 1;
    if(s - e + 1 >= 0) {
        if(oven[s] >= r) return s;
        else return -1;
    }
    int mid = (s + e) / 2;
    if(oven[mid] >= r) return binary_search(mid, e, r);
    else return binary_search(s, mid, r);
}

int main() {
    cin >> D >> N;
    oven.resize(D);
    for(int i = 0; i < D; i++) cin >> oven[i];
    int pre_size = oven[0];
    
    for(int i = 1; i < D; i++) {
        oven[i] = min(pre_size, oven[i]);
        pre_size = oven[i];
    }
    
    int res = D;
    for(int i = 0; i < N; i++) {
        int r;
        cin >> r;
        res = binary_search(0, res, r);
    }
    
    cout << res + 1 << "\n";
    return 0;
}
