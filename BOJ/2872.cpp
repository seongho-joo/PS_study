//
//  2872.cpp
//  test
//
//  Created by 주성호 on 2020/07/16.
//  Copyright © 2020 주성호. All rights reserved.
//
//  https://www.acmicpc.net/problem/2872
//  BOJ2872 우리집엔 도서관이 있어 : 이분 탐색, 구현, 그리디 알고리즘

#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int N, check, ans = 0;
    vector<int> arr;
    
    cin >> N;
    arr.resize(N);
    
    check = N;
    
    for(int i = 0; i < N; i++) cin >> arr[i];
    
    for(int i = N - 1; i >= 0; i--) {
        if(check == arr[i]) check -= 1;
        else ans += 1;
    }
    
    cout << ans << "\n";
    
    return 0;
}
