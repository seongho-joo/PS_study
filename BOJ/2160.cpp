//
//  2160.cpp
//  OnlineJudge
//
//  Created by 주성호 on 2020/06/15.
//  Copyright © 2020 주성호. All rights reserved.
//
//  https://www.acmicpc.net/problem/2160 그림 비교

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

struct Paint {
    int a, b, cnt;
    Paint() : a(0), b(0), cnt(0) {}
    Paint(int i, int j, int cnt) : a(i), b(j), cnt(cnt) {}
    bool operator < (const Paint& A) const {
        return cnt < A.cnt;
    }
};
vector<vector<vector<char> > > paint;
vector<Paint> ans;
vector<bool> checked;

void solve(int n) {
    for(int i = 0; i < n; i++) {
        checked[i] = true;
        for(int j = 0; j < n; j++) {
            if(i != j && !checked[j]) {
                int diff = 0;
                for(int k = 0; k < 5; k++)
                    for(int l = 0; l < 7; l++)
                        if(paint[i][k][l] != paint[j][k][l]) diff += 1;
                ans.push_back(Paint(i, j, diff));
            }
        }
    }
    sort(ans.begin(), ans.end());
    cout << ans[0].a + 1 << " " << ans[0].b + 1 << "\n";
}

int main() {
    int n;
    cin >> n;
    checked.resize(n, false);
    paint.resize(n, vector<vector<char> >(5, vector<char>(7)));

    for(int i = 0; i < n; i++)
        for(int j = 0; j < 5; j++)
            for(int k = 0; k < 7; k++) cin >> paint[i][j][k];
    
    solve(n);
    return 0;
}
