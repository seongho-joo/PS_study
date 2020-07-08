//
//  2506.cpp
//  OnlineJudge
//
//  Created by 주성호 on 2020/06/15.
//  Copyright © 2020 주성호. All rights reserved.
//
//  https://www.acmicpc.net/problem/2506 점수계산

#include <iostream>
#include <vector>
using namespace std;

vector<pair<int, int> > arr;
int score, res;

int main() {
    int n;
    cin >> n;
    arr.resize(n);
    
    for(int i = 0; i < n; i++) cin >> arr[i].first;
    if(arr[0].first) arr[0].second = 1;
    else arr[0].second = 0;
    for(int i = 1; i < n; i++) {
        if(arr[i].first) {
            if(arr[i].first == arr[i - 1].first) arr[i].second = arr[i - 1].second + 1;
            else arr[i].second = 1;
        } else arr[i].second = 0;
    }
    for(int i = 0; i < n; i++) res += arr[i].second;
    cout << res << "\n";
    
    return 0;
}
