//
//  3054.cpp
//  test
//
//  Created by 주성호 on 2020/07/09.
//  Copyright © 2020 주성호. All rights reserved.
//
//  https://www.acmicpc.net/problem/3054
//  BOJ3054 피터팬 프레임 : 구현

#include <iostream>
#include <string>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string str, result[5];
    cin >> str;
    
    result[0] = "..#..";
    for(int i = 1; i < str.length(); i++) {
        if(i % 3 == 2) result[0] += ".*..";
        else result[0] += ".#..";
    }
    result[4] = result[0];
    
    result[1] = ".#.#.";
    for(int i = 1; i < str.length(); i++) {
        if(i % 3 == 2) result[1] += "*.*.";
        else result[1] += "#.#.";
    }
    result[3] = result[1];
    
    result[2] = "#.";
    result[2] += str[0];
    result[2] += ".#";
    for(int i = 1; i < str.length(); i++) {
        result[2] += ".";
        result[2] += str[i];
        if(i % 3 == 2) result[2] += ".*";
        else if (i % 3 == 1) {
            if(i == str.length() - 1) result[2] += ".#";
            else result[2] += ".*";
        }
        else result[2] += ".#";
    }
    for(int i = 0; i < 5; i++) cout << result[i] << "\n";
    return 0;
}
