//
//  10551.cpp
//  test
//
//  Created by 주성호 on 2020/07/23.
//  Copyright © 2020 주성호. All rights reserved.
//
//  https://www.acmicpc.net/problem/10551
//  BOJ10551 STROJOPIS : 문자열 처리, 구현

#include <iostream>
#include <string>
using namespace std;

int cnt[8];

int main() {
    string str;
    getline(cin, str);
    
    for(int i = 0; i < str.size(); i++) {
        if(str[i] == '1' || str[i] == 'Q' || str[i] == 'A' || str[i] == 'Z') cnt[0] += 1;
        else if(str[i] == '2' || str[i] == 'W' || str[i] == 'S' || str[i] == 'X') cnt[1] += 1;
        else if(str[i] == '3' || str[i] == 'E' || str[i] == 'D' || str[i] == 'C') cnt[2] += 1;
        else if(str[i] == '4' || str[i] == '5' || str[i] == 'R' || str[i] == 'T' || str[i] == 'F' || str[i] == 'G' || str[i] == 'V' || str[i] == 'B') cnt[3] += 1;
        else if(str[i] == '6' || str[i] == '7' || str[i] == 'Y' || str[i] == 'U' || str[i] == 'H' || str[i] == 'J' || str[i] == 'N' || str[i] == 'M') cnt[4] += 1;
        else if(str[i] == '8' || str[i] == 'I' || str[i] == 'K' || str[i] == ',') cnt[5] += 1;
        else if(str[i] == '9' || str[i] == 'O' || str[i] == 'L' || str[i] == '.') cnt[6] += 1;
        else if(str[i] == '0' || str[i] == 'P' || str[i] == ';' || str[i] == '/' || str[i] == '-' || str[i] == '[' || str[i] == ']' || str[i] == '=' || str[i] == '\'') cnt[7] += 1;
    }
    
    for(int i : cnt) cout << i << "\n";
    
    return 0;
}
