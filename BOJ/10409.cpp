//
//  10409.cpp
//  OnlineJudge
//
//  Created by 주성호 on 2020/07/02.
//  Copyright © 2020 주성호. All rights reserved.
//
//  https://www.acmicpc.net/problem/10409 서버

#include <iostream>
#include <vector>
using namespace std;

vector<int> request;

int main() {
    int n, t, cur = 0, cnt = 0;
    cin >> n >> t;
    
    request.resize(n);
    for(int i = 0; i < n; i++) cin >> request[i];
    
    for(int i : request) {
        if(cur + i > t) break;
        cur += i;
        cnt += 1;
    }
    cout << cnt << "\n";
    return 0;
}
