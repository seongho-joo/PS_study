//
//  11656.cpp
//  PS_Study
//
//  Created by 주성호 on 2020/10/05.
//  Copyright © 2020 주성호. All rights reserved.
//
//  https://www.acmicpc.net/problem/11656
//  BOJ11656 접미사 배열 : 문자열, 정렬

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    string str;
    cin >> str;
    vector<string> arr;
    
    while(!str.empty()) {
        arr.push_back(str);
        str.erase(str.begin());
    }
    
    sort(arr.begin(), arr.end());
    
    for(auto i : arr) {
        cout << i << "\n";
    }
    
    return 0;
}
