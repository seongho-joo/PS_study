//
//  6581.cpp
//  test
//
//  Created by 주성호 on 2020/07/23.
//  Copyright © 2020 주성호. All rights reserved.
//
//  https://www.acmicpc.net/problem/6581
//  BOJ6581 HTML : 문자열 처리, 구현, 파싱

#include <iostream>
#include <string>
using namespace std;

int main() {
    string str;
    int sum = 0;
    while((cin >> str)) {
        if(str == "<br>") {
            cout << "\n";
            sum = 0;
        } else if (str == "<hr>") {
            if(sum == 0) {
                for(int i = 0; i < 80; i++) cout << "-";
                cout << "\n";
            } else {
                cout << "\n";
                for(int i = 0; i < 80; i++) cout << "-";
                cout << "\n";
                sum = 0;
            }
        } else {
            int len = str.size();
            if(sum == 0) {
                sum = len;
                cout << str << " ";
                sum += 1;
            } else if(sum + len + 1 <= 80) {
                sum += len;
                cout << str << " ";
                sum += 1;
                if(sum == 80) {
                    cout << "\n";
                    sum = 0;
                }
            } else {
                cout << "\n";
                sum = len;
                cout << str << " ";
                sum += 1;
            }
        }
    }
    return 0;
}
