//
//  2501.cpp
//  test
//
//  Created by 주성호 on 2020/07/25.
//  Copyright © 2020 주성호. All rights reserved.
//
//  https://www.acmicpc.net/problem/2501
//  BOJ2501 약수 구하기 : 수학

#include <iostream>
using namespace std;

int N, K;

int solve() {
    for(int i = 1; i <= N; i++) {
        if(N % i == 0) {
            K -= 1;
            if(!K) return i;
        }
    }
    return 0;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N >> K;
    cout << solve() << "\n";
    return 0;
}
