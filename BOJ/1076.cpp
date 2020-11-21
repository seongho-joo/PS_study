//
//  1076.cpp
//  test
//
//  Created by 주성호 on 2020/11/21.
//  Copyright © 2020 주성호. All rights reserved.
//
//  https://www.acmicpc.net/problem/1076
//  BOJ1076 저항 : 구현

#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main() {
    string color[] = {"black", "brown", "red", "orange", "yellow", "green","blue","violet", "grey", "white"};
    string c1, c2, c3;
    cin >> c1 >> c2 >> c3;
    long long a, b, c;
    for(int i = 0; i < 10; i++) {
        if(c1 == color[i]) a = i;
        if(c2 == color[i]) b = i;
        if(c3 == color[i]) c = i;
    }
    
    long long res = (a * 10 + b) * powl(10, c);
    
    cout << res << "\n";
    return 0;
}
