//
//  1032.cpp
//  test
//
//  Created by 주성호 on 2020/08/26.
//  Copyright © 2020 주성호. All rights reserved.
//
//  https://www.acmicpc.net/problem/1032
//  BOJ1032 명령 프롬프트 : 구현, 문자열

#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<string> v;
string common;

void solution() {
    int length = (int)v[0].size();
    for(int i = 0; i < length; i++) {
        bool flag = false;
        char pre = v[0][i];
        for(int j = 1; j < v.size(); j++) {
            if(pre != v[j][i]) {
                flag = true;
                break;
            }
        }
        if(!flag) {
            common.push_back(pre);
        } else {
            common.push_back('?');
        }
    }

    cout << common << "\n";
}

int main() {
    int n;
    cin >> n;
    v.resize(n);
    
    for(int i = 0; i < n; i++) {
        cin >> v[i];
    }
    
    solution();
    
    return 0;
}
