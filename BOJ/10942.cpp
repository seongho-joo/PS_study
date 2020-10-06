//
//  10942.cpp
//  test
//
//  Created by 주성호 on 2020/10/06.
//  Copyright © 2020 주성호. All rights reserved.
//
//  https://www.acmicpc.net/problem/10942
//  BOJ10942 팰린드롬? : 다이나믹 프로그래밍, 문자열

#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

vector<vector<bool> > dp;
vector<int> arr;
int n, m, s, e;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    arr.resize(n);
    dp.resize(n, vector<bool>(n, false));
    
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
        dp[i][i] = true;
        if(i != 0 && arr[i] == arr[i - 1]) {
            dp[i - 1][i] = true;
        }
    }
    // i는 s에서 e까지의 길이
    for(int i = 2; i < n; i++) {
        for(int j = 0; j < n - i; j++) {
            // arr[s] 와 arr[e]가 같고 dp[s + 1][e - 1] 가 true일 경우 팰린드롬
            if(arr[j] == arr[j + i] && dp[j + 1][j + i - 1]) {
                dp[j][j + i] = true;
            }
        }
    }
    
    cin >> m;
    
    for(int i = 0; i < m; i++) {
        cin >> s >> e;
        int res = 0;
        if(dp[s - 1][e - 1]) res = 1;
        cout << res << "\n";
    }
    
    return 0;
}
