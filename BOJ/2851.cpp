//
//  2851.cpp
//  OnlineJudge
//
//  Created by 주성호 on 2020/05/30.
//  Copyright © 2020 주성호. All rights reserved.
//
//  https://www.acmicpc.net/problem/2851 슈퍼 마리오

#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int arr[10], sum = 0;
    for(int i = 0; i < 10; i++) cin >> arr[i];
    for(int i = 0; i < 10; i++) {
        sum += arr[i];
        if(sum == 100) break;
        if(sum + arr[i + 1] > 100) {
            int cur = 100 - sum;
            int next = abs(100 - (sum + arr[i + 1]));
            if(cur < next) break;
            else if(cur > next) sum += arr[i + 1];
            else sum = (sum < sum + arr[i + 1] ? sum + arr[i + 1] : sum);
            break;
        }
    }
    cout << sum << "\n";
    return 0;
}
