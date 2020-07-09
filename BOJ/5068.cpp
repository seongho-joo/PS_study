//
//  5068.cpp
//  test
//
//  Created by 주성호 on 2020/07/09.
//  Copyright © 2020 주성호. All rights reserved.
//
//  https://www.acmicpc.net/problem/5086
//  BOJ5086 배수와 약수 : 구현, 수학

#include <iostream>
#include <string>
using namespace std;

int main() {
    int a, b;
    while(cin >> a >> b, a != 0) {
        string res;
        if(a < b && b % a == 0) res = "factor\n";
        else if( a > b && a % b == 0) res = "multiple\n";
        else res = "neither\n";
        
        cout << res;
    }
    return 0;
}
