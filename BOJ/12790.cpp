//
//  12790.cpp
//  OnlineJudge
//
//  Created by 주성호 on 2020/06/30.
//  Copyright © 2020 주성호. All rights reserved.
//
//  https://www.acmicpc.net/problem/12790  Mini Fantasy War

#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        int h, m, o, d, H, M, O, D;
        cin >> h >> m >> o >> d >> H >> M >> O >> D;
        h = (h + H) <= 1 ? 1 : h + H;
        m = (m + M) <= 1 ? 1 : m + M;
        o = (o + O) <= 0 ? 0 : o + O;
        d = (d + D);
        cout << 1 * h + 5 * m + 2 * o +  2 * d << "\n";
    }
    return 0;
}
