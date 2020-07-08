//
//  10539.cpp
//  OnlineJudge
//
//  Created by 주성호 on 2020/06/30.
//  Copyright © 2020 주성호. All rights reserved.
//
//  https://www.acmicpc.net/problem/10539 수빈이와 수열

#include <iostream>
#include <vector>
using namespace std;

vector<int> arr, ans;

int main() {
    int n;
    cin >> n;
    arr.resize(n); ans.resize(n);
    
    for(int i = 0; i < n; i++) cin >> arr[i];
    int sum = arr[0] * 1;
    ans[0] = sum;
    for(int i = 1; i < n; i++) {
        ans[i] = arr[i] * (i + 1) - sum;
        sum += ans[i];
    }
    
    for(int i = 0; i < n; i++) cout << ans[i] << " ";
    cout << "\n";
    return 0;
}
