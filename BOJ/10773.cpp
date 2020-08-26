//
//  10773.cpp
//  test
//
//  Created by 주성호 on 2020/08/26.
//  Copyright © 2020 주성호. All rights reserved.
//
//  https://www.acmicpc.net/problem/10773
//  BOJ10773 제로 : 구현, 자료구조, 문자열, 스택

#include <iostream>
#include <stack>
using namespace std;

int main() {
    stack<int> st;
    int n, op, res = 0;
    cin >> n;
    while(n--) {
        cin >> op;
        if(op != 0) st.push(op);
        else st.pop();
    }
    
    while(!st.empty()) {
        res += st.top();
        st.pop();
    }
    
    cout << res << "\n";
    
    return 0;
}
