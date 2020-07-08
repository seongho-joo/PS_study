//
//  10707.cpp
//  OnlineJudge
//
//  Created by 주성호 on 2020/07/02.
//  Copyright © 2020 주성호. All rights reserved.
//
//  https://www.acmicpc.net/problem/10707   수도요금

#include <iostream>
using namespace std;

int main() {
    int x_A, y_B, y_max, y_extraCharge, p, result;
    cin >> x_A >> y_B >> y_max >> y_extraCharge >> p;
    
    if(p <= y_max) result = x_A * p < y_B ? x_A * p : y_B;
    else {
        int dif = p - y_max;
        result = x_A * p < y_B + dif * y_extraCharge ? x_A * p : y_B + dif * y_extraCharge;
    }
    
    cout << result << "\n";
    
    return 0;
}
