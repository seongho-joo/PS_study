//
//  2631.cpp
//  OnlineJudge
//
//  Created by 주성호 on 2020/05/30.
//  Copyright © 2020 주성호. All rights reserved.
//
//  https://www.acmicpc.net/problem/2631 줄세우기

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, INF = 987654321, num;
    vector<int> lis;
    cin >> n;
    lis.push_back(-INF);
    for(int i = 0; i < n; i++) {
        cin >> num;
        if(lis.back() < num) lis.push_back(num);
        else {
            auto idx = lower_bound(lis.begin(), lis.end(), num);
            *idx = num;
        }
    }
    
    cout << n - (lis.size() - 1) << "\n";
    return 0;
}
