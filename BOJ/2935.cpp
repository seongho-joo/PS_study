//
//  2935.cpp
//  OnlineJudge
//
//  Created by 주성호 on 2020/06/30.
//  Copyright © 2020 주성호. All rights reserved.
//
//  https://www.acmicpc.net/problem/2935 소음

#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

string ans, a, b;

int main() {
    char op;
    cin >> a >> op >> b;

    if(op == '*') {
        for(int i = 0; i < b.size() - 1; i++) a.push_back('0');
        cout << a << "\n";
    }
    else {
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        if(a.size() < b.size()) ans = b;
        else ans = a;
        int Min = min(a.size(), b.size());
        for(int i = 0; i < Min; i++) {
            if(a[i] == '0' && b[i] == '0') ans[i] = '0';
            else if((a[i] == '1' && b[i] == '0') || (a[i] == '0' && b[i] == '1')) ans[i] = '1';
            else ans[i] = '2';
        }
        reverse(ans.begin(), ans.end());
        cout << ans << "\n";
    }
    
    return 0;
}
