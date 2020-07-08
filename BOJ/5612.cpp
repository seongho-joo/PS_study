//
//  5612.cpp
//  OnlineJudge
//
//  Created by 주성호 on 2020/07/08.
//  Copyright © 2020 주성호. All rights reserved.
//
//  https://www.acmicpc.net/problem/5612
//  BOJ5612 터널의 입구와 출구 : 구현

#include <iostream>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    int Max = m;
    for (int i = 0; i < n; i++) {
        int in, out;
        cin >> in >> out;
        m += in - out;
        if (m < 0) {
            cout << 0;
            return 0;
        }
        Max = m < Max ? Max : m;
    }
    cout << Max << "\n";

    return 0;
}
