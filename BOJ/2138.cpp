//
//  2138.cpp
//  test
//
//  Created by 주성호 on 2020/07/13.
//  Copyright © 2020 주성호. All rights reserved.
//
//  https://www.acmicpc.net/problem/2138
//  BOJ2138 전구와 스위치 : 구현, 그리디알고리즘

#include <iostream>
#include <string>
using namespace std;

int N, ans = 987654321;
string s, copyS, result;

void push(int n) {
    if(n > 0) copyS[n - 1] = copyS[n - 1] == '0' ? '1' : '0';
    copyS[n] = copyS[n] == '0' ? '1' : '0';
    if(n < N - 1) copyS[n + 1] = copyS[n + 1] == '0' ? '1' : '0';
}

void solve(int n, int cnt) {
    if(n == N - 1) {
        if(copyS == result) ans = ans < cnt ? ans : cnt;
        push(n);
        if(copyS == result) ans = ans < cnt + 1 ? ans : cnt + 1;
        
        return;
    }
    
    if(copyS[n - 1] == result[n - 1]) solve(n + 1, cnt);
    push(n);
    if(copyS[n - 1] == result[n - 1]) solve(n + 1, cnt + 1);
    push(n);
}

int main() {
    cin >> N;
    cin >> s >> result;
    copyS = s;
    
    solve(1, 0);
    
    copyS = s;
    push(0);
    solve(1, 1);
    
    cout << (ans == 987654321 ? -1 : ans) << "\n";
    
    return 0;
}
