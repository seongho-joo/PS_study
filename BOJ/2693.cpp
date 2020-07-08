//
//  2693.cpp
//  OnlineJudge
//
//  Created by 주성호 on 2020/05/30.
//  Copyright © 2020 주성호. All rights reserved.
//
//  https://www.acmicpc.net/problem/2693 N번째 큰 수

#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int T;
    int arr[10];
    cin >> T;
    while(T--) {
        for(int i = 0; i < 10; i++) cin >> arr[i];
        sort(arr, arr + 10, greater<int>());
        cout << arr[2] << "\n";
    }
    return 0;
}
