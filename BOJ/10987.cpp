//
//  10987.cpp
//  test
//
//  Created by 주성호 on 2020/10/07.
//  Copyright © 2020 주성호. All rights reserved.
//
//  https://www.acmicpc.net/problem/10987
//  BOJ10987 모음의 개수 : 구현, 문자열

#include <string>
#include <iostream>
using namespace std;

int main() {
    string str;
    cin >> str;
    int res = 0;
    for(int i = 0; i < str.length(); i++) {
        if(str[i] == 'e' || str[i] == 'a' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u')
            res += 1;
    }
    cout << res << "\n";
    return 0;
}
