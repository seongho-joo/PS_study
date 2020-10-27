//
//  10799.cpp
//  PS_Study
//
//  Created by 주성호 on 2020/10/27.
//  Copyright © 2020 주성호. All rights reserved.
//
//  https://www.acmicpc.net/problem/10799
//  BOJ10799 쇠막대기 : 자료구조, 스택

#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    string inp;
    cin >> inp;
    int result = 0;
    stack<char> st;
    
    for(int i = 0; i < inp.size(); i++) {
        if(inp[i] == '(') {
            st.push(inp[i]);
        } else {
            if(!st.empty()) {
                st.pop();
                // 레이저를 만났을 경우 스택의 사이즈 만큼 더해줌
                if(inp[i - 1] == '(') {
                    result += st.size();
                } else { // 쇠막대기 마지막 잘린 부분 + 1
                    result += 1;
                }
            }
        }
    }
    
    cout << result << "\n";
    
    return 0;
}
