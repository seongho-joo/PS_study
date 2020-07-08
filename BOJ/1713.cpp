//
//  1713.cpp
//  OnlineJudge
//
//  Created by 주성호 on 2020/07/07.
//  Copyright © 2020 주성호. All rights reserved.
//
//  https://www.acmicpc.net/problem/1713 후보 추천하기

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

typedef pair<int, int> pii;
vector<int> recommend;
vector<pii> ans;
bool check[101];
int n, candidateNum;

void removeCandidate() {
    int Min = 987654321;
    for(int i = 0; i < ans.size(); i++) Min = Min > ans[i].second ? ans[i].second : Min;
    for(int i = 0; i < ans.size(); i++) {
        if(Min == ans[i].second) {
            check[ans[i].first] = false;
            ans.erase(ans.begin() + i);
            break;
        }
    }
}

void solve() {
    for(int i = 0; i < candidateNum; i++) {
        if(!check[recommend[i]]) {
            if(ans.size() == n) removeCandidate();
            check[recommend[i]] = true;
            ans.push_back({recommend[i], 1});
        } else {
            for(int j = 0; j < n; j++)
                if(recommend[i] == ans[j].first) {
                    ans[j].second += 1;
                    break;
                }
        }
    }
    sort(ans.begin(), ans.end());
    for(pii i : ans) cout << i.first << " ";
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> candidateNum;
    recommend.resize(candidateNum);
    ans.reserve(n);
    
    for(int i = 0; i < candidateNum; i++) cin >> recommend[i];
    
    solve();
    
    return 0;
}
