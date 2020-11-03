//
//  2010.cpp
//  test
//
//  Created by 주성호 on 2020/11/03.
//  Copyright © 2020 주성호. All rights reserved.
//
//  https://www.acmicpc.net/problem/2010
//  BOJ2010 플러그 : 수학, 구현, 사칙연산

#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N, inp, res = 0;
    cin >> N;
    
    vector<int> powerStrip(N);
    
    for(int i = 0; i < N; i++) {
        cin >> powerStrip[i];
        if(i != 0) {
            powerStrip[i - 1] -= 1;
        }
    }
    
    for(auto i : powerStrip) {
        res += i;
    }
    
    cout << res << "\n";
    return 0;
}
