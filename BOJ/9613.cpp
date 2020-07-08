//
//  9613.cpp
//  OnlineJudge
//
//  Created by 주성호 on 2020/06/30.
//  Copyright © 2020 주성호. All rights reserved.
//
//  https://www.acmicpc.net/problem/9613 GCD 합

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

typedef long long lint;
lint sum = 0;
vector<bool> check;

int gcd(int a, int b) {
    if(a < b) swap(a, b);
    return a % b ? gcd(b, a % b) : b;
}

void solve(vector<int> arr) {
    for(int i = 0; i < arr.size(); i++) {
        check[i] = true;
        for(int j = 0; j < arr.size(); j++)
            if(i != j && !check[j]) sum += gcd(arr[i], arr[j]);
    }
}

int main() {
    int T;
    cin >> T;
    
    while(T--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        check.resize(n);
        for(int i = 0; i < n; i++) cin >> arr[i];
        solve(arr);
        cout << sum << "\n";
        check.clear();
        sum = 0;
    }
    return 0;
}
