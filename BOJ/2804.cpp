//
//  2804.cpp
//  OnlineJudge
//
//  Created by 주성호 on 2020/06/30.
//  Copyright © 2020 주성호. All rights reserved.
//
//  https://www.acmicpc.net/problem/2804 크로스워드 만들기
 
#include <iostream>
#include <string>
using namespace std;

int main() {
    string a, b;
    cin >> a >> b;
    
    int y = -1, x = -1;
    
    for(int i = 0; i < a.size(); i++) {
        for(int j = 0; j < b.size(); j++) {
            if(a[i] == b[j]) {
                x = i; y = j;
                break;
            }
        }
        if(y != -1 && x != -1) break;
    }
    
    for(int i = 0; i < b.size(); i++) {
        if(i == y) {
            cout << a << "\n";
            continue;;
        }
        for(int j = 0; j < a.size(); j++) {
            if(j != x) cout << ".";
            else cout << b[i];
        }
        cout << "\n";
    }
    return 0;
}
