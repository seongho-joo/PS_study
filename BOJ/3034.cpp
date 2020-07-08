//
//  3034.cpp
//  OnlineJudge
//
//  Created by 주성호 on 2020/06/30.
//  Copyright © 2020 주성호. All rights reserved.
//
//  https://www.acmicpc.net/problem/3034 앵그리 창영

#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int n, w, h, diagonal;
    cin >> n >> w >> h;
    diagonal = sqrt(w * w + h * h);
    while(n--) {
        int a;
        cin >> a;
        if(w >= a || h >= a || diagonal >= a) cout << "DA\n";
        else cout << "NE\n";
    }
    return 0;
}
