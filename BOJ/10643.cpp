//
//  10643.cpp
//  test
//
//  Created by 주성호 on 2020/07/24.
//  Copyright © 2020 주성호. All rights reserved.
//
//  https://www.acmicpc.net/problem/10643
//  BOJ10643 FUNGHI : 구현

#include <iostream>
using namespace std;

int main() {
    int pizza[8];
    for(int i = 0; i < 8; i++) cin >> pizza[i];
    int max = 0;
    for(int i = 0; i < 8; i++) {
        int sum = 0;
        for(int j = i; j != (i + 4) % 8; j = (j + 1) % 8) sum += pizza[j];
        max = max < sum ? sum : max;
    }
    cout << max << "\n";
    return 0;
}
