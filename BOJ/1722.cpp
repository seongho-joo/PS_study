//
//  1722.cpp
//  OnlineJudge
//
//  Created by 주성호 on 2020/07/02.
//  Copyright © 2020 주성호. All rights reserved.
//
//  https://www.acmicpc.net/problem/1722 순열의 순서

#include <iostream>
#include <vector>
using namespace std;

typedef long long lint;

lint dp[21], k;
bool check[21];
int n, op, arr[21];

void getFactorial() {
    dp[1] = 1;
    dp[2] = 2;
    for(int i = 3; i < 21; i++) dp[i] = i * dp[i - 1];
}
void query1() {
    int ans[21];
    for(int i = 0; i < n; i++) {
        for(int j = 1; j <= n; j++) {
            if(!check[j]) {
                if(dp[n - i - 1] < k && k > 1) {
                    k -= dp[n - i - 1];
                } else {
                    ans[i] = j;
                    check[j] = true;
                    break;
                }
            }
        }
    }
    for(int i = 0 ; i < n; i++) cout << ans[i] << " ";
    cout << "\n";
}

void query2() {
    lint ans = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 1; j < arr[i]; j++)
            if(!check[j]) ans += dp[n - i - 1];
        check[arr[i]] = true;
    }
    cout << ans + 1 << "\n";
}

int main() {
    getFactorial();
    cin >> n >> op;
    if(op == 1) {
        cin >> k;
        query1();
    } else {
        for(int i = 0; i < n; i++) cin >> arr[i];
        query2();
    }
    return 0;
}
