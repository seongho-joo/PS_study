//
//  1541.cpp
//  test
//
//  Created by 주성호 on 2020/09/25.
//  Copyright © 2020 주성호. All rights reserved.
//
//  https://www.acmicpc.net/problem/1541
//  BOJ1541 잃어버린 괄호 : 수학, 그리디, 문자열, 파싱

#include <iostream>
#include <string>
using namespace std;

int main () {
    string str;
    cin >> str;
    int res = 0;
    bool minus = false;
    int num = 0;
    for (int i = 0; i <= str.length(); i++) {
        if (str[i] == '-' || str[i] == '+' || str[i] == '\0') {
            num /= 10;
            if(minus) {
                res -= num;
            }
            else {
                res += num;
            }

            if(str[i] == '-') minus = true;
            num = 0;
        } else {
            num += (str[i] - '0');
            num *= 10;
        }
    }
    cout << res << "\n";
    return 0;
}
