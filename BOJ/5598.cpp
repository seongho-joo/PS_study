//
//  5598.cpp
//  OnlineJudge
//
//  Created by 주성호 on 2020/04/24.
//  Copyright © 2020 주성호. All rights reserved.
//
//  https://www.acmicpc.net/problem/5598 : 카이사르 암호

#include <iostream>
#include <string>
using namespace std;

int main() {
    string str;
    cin >> str;
    
    int ascii;
    for(int i = 0; i < str.size(); i++) {
        ascii = str[i] - 3;
        if(ascii < 65) ascii += 26;
        str[i] = ascii;
    }
    
    cout << str << "\n";
    
    return 0;
}
