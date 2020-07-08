//
//  1259.cpp
//  OnlineJudge
//
//  Created by 주성호 on 2020/06/15.
//  Copyright © 2020 주성호. All rights reserved.
//
//  https://www.acmicpc.net/problem/1259 팰린드롬수

#include <iostream>
#include <string>
using namespace std;

string num;

bool isPalindrome() {
    for(int i = 0, j = num.size() - 1; i < num.size() / 2; i++, j--)
        if(num[i] != num[j]) return false;
    return true;
}

int main() {
    while(static_cast<void>(cin >> num), num != "0") {
        cout << (isPalindrome() ? "yes" : "no") << "\n";
    }
    return 0;
}
