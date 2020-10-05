//
//  11655.cpp
//  PS_Study
//
//  Created by 주성호 on 2020/10/05.
//  Copyright © 2020 주성호. All rights reserved.
//
//  https://www.acmicpc.net/problem/11655
//  BOJ11655 ROT13 : 문자열

#include <iostream>
#include <string>
using namespace std;

int main() {
    string str, res;
    getline(cin, str);
    
    for(int i = 0; i < str.length(); i++) {
        if (str[i] >= 'A' && str[i] <= 'Z') {
            if(str[i] + 13 <= 'Z') {
                res.push_back(str[i] + 13);
            } else {
                int temp = (str[i] + 13) - 'Z' - 1;
                res.push_back('A' + temp);
            }
        } else if (str[i] >= 'a' && str[i] <= 'z'){
            if(str[i] + 13 <= 'z') {
                res.push_back(str[i] + 13);
            } else {
                int temp = (str[i] + 13) - 'z' - 1;
                res.push_back('a' + temp);
            }
        } else {
            res.push_back(str[i]);
        }
    }
    
    cout << res << "\n";
    
    return 0;
}
