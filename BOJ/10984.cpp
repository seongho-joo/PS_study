//
//  10984.cpp
//  OnlineJudge
//
//  Created by 주성호 on 2020/07/02.
//  Copyright © 2020 주성호. All rights reserved.
//
//  https://www.acmicpc.net/problem/10984 내 학점을 구해줘

#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int T;
    cin >> T;
    
    while(T--) {
        int total_credit = 0;
        double total_g = 0.0;
        int N;
        cin >> N;
        for(int i = 0; i < N; i++) {
            int c; double g;
            cin >> c >> g;
            total_credit += c;
            total_g += (c * g);
        }
        cout << fixed;
        cout.precision(1);
        cout << total_credit << " " << total_g / total_credit << "\n";
    }
    return 0;
}
