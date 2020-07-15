//
//  2037.cpp
//  test
//
//  Created by 주성호 on 2020/07/15.
//  Copyright © 2020 주성호. All rights reserved.
//
//  https://www.acmicpc.net/problem/2037
//  BOJ2037 문자메시지 : 구현

#include <iostream>
#include <string>
using namespace std;

int num[26] = {12, 22, 32, 13, 23, 33, 14, 24, 34, 15, 25, 35, 16, 26, 36, 17, 27, 37, 47, 18, 28, 38, 19, 29, 39, 49 };

string word;

int main() {
    int p, w, res = 0;
    int idx, seq, cur, pre = -1;
    cin >> p >> w;
    getline(cin, word);
    getline(cin, word);
    
    for(char i : word) {
        if(i == ' ') {
            res += p;
            pre = -1;
        }
        else {
            idx = i - 'A';
            seq = num[idx] / 10; // 순번
            cur = num[idx] % 10; // 현재 번호
            
            if(pre == cur) res += w;
            res += (seq * p);
            
            pre = cur;
        }
    }
    cout << res << "\n";
    return 0;
}
