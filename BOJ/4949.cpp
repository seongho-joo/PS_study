//
//  4949.cpp
//  test
//
//  Created by 주성호 on 2020/07/29.
//  Copyright © 2020 주성호. All rights reserved.
//
//  https://www.acmicpc.net/problem/4949
//  BOJ4949 균형잡힌 세상 : 문자열 처리, 스택, 자료구조

#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool isBallenced(char a, stack<char>& st) {
    switch (a) {
        case ')':
            if(!st.empty()) {
                if(st.top() == '(')
                    st.pop();
                else return false;
            }
            else return false;
            break;
        case ']':
             if(!st.empty()) {
                if(st.top() == '[')
                    st.pop();
                else return false;
               }
            else return false;
            break;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string s;
    while(true) {
        getline(cin, s);
        stack<char> st;
        bool flag= true;
        if(s.length() == 1 && s == ".") break;
        for(int i = 0; i < s.length(); i++) {
            if(s[i] == '(' || s[i] == '[')
                st.push(s[i]);
            else if(s[i] == ')' || s[i] == ']') {
                flag = isBallenced(s[i], st);
                if(!flag) break;
            }
            else continue;
        }
        if(!flag || !st.empty()) cout << "no\n";
        else cout << "yes\n";
    }
    return 0;
}
