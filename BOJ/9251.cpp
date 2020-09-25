//
//  9251.cpp
//  test
//
//  Created by 주성호 on 2020/09/25.
//  Copyright © 2020 주성호. All rights reserved.
//
//  https://www.acmicpc.net/problem/9251
//  BOJ9251 LCS : 다이나믹 프로그래밍, 문자열

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

string A, B;
vector<vector<int> > dp;

int main() {
    cin >> A >> B;
    int aSize = (int)A.size();
    int bSize = (int)B.size();
    dp.resize(aSize + 1, vector<int>(bSize + 1, 0));
    int ans = 0;
    
    for(int i = 1; i <= aSize; i++) {
        for(int j = 1; j <= bSize; j++) {
            if (A[i - 1] == B[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
            ans = max(ans, dp[i][j]);
        }
    }
    cout << ans << "\n";
    return 0;
}
