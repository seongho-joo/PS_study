//
//  5397.cpp
//  test
//
//  Created by 주성호 on 2020/10/13.
//  Copyright © 2020 주성호. All rights reserved.
//
//  https://www.acmicpc.net/problem/5397
//  BOJ5397 키로거 : 자료 구조, 덱

#include <string>
#include <iostream>
#include <list>

using namespace std;

list<char> res;

void solution (string inp) {
    auto cursor = res.begin();
    for (char i : inp) {
        if (i == '<') {
            if (cursor != res.begin()) {
                cursor--;
            }
        } else if (i == '>') {
            if (cursor != res.end()) {
                cursor++;
            }
        } else if (i == '-') {
            if(cursor != res.begin()) {
                cursor--;
                cursor = res.erase(cursor);
            }
        } else {
            res.insert(cursor, i);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T;
    cin >> T;
    
    while (T--) {
        res.clear();
        string inp;
        cin >> inp;
        solution(inp);
        for(char i : res) {
            cout << i;
        }
        cout << "\n";
    }
    
    return 0;
}

