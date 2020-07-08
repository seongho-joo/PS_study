//
//  3047.cpp
//  OnlineJudge
//
//  Created by 주성호 on 2020/05/21.
//  Copyright © 2020 주성호. All rights reserved.
//
//  https://www.acmicpc.net/problem/3047 ABC

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int arr[3];
    for(int i = 0; i < 3;i ++) cin >> arr[i];
    string query;
    cin >> query;
    sort(arr, arr + 3);
    
    for(int i = 0; i < 3; i++) {
        if(query[i] == 'A') cout << arr[0] << " ";
        else if(query[i] == 'B') cout << arr[1] << " ";
        else cout << arr[2] << " ";
    }
    cout << "\n";
    return 0;
}
