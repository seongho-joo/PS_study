//
//  10808.cpp
//  OnlineJudge
//
//  Created by 주성호 on 2020/04/20.
//  Copyright © 2020 주성호. All rights reserved.
//
//  https://www.acmicpc.net/problem/10808
//  알파벳 개수

#include <iostream>
#include <string>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    string str;
    int alphabet[27] = {0};
    
    cin >> str;
    
    for(int i = 0; i < str.length(); i++) alphabet[str[i] - 97] += 1;
    
    for(int i = 0; i < 26; i++) cout << alphabet[i] << ' ';
    
    return 0;
}
