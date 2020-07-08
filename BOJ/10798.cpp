//
//  10798.cpp
//  OnlineJudge
//
//  Created by 주성호 on 2020/07/01.
//  Copyright © 2020 주성호. All rights reserved.
//
//  https://www.acmicpc.net/problem/10798 세로읽기

#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    vector<string> v;
    string str;
    
    for(int i = 0; i < 5; i++) {
        cin >> str;
        v.push_back(str);
    }
    
    for(int i = 0; i < 15; i++) {
        for(int j = 0; j < 5; j++) {
            if(v[j].size() - 1< i) continue;
            cout << v[j][i];
        }
    }
    cout << "\n";
    return 0;
}
