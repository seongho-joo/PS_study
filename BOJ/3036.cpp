//
//  3036.cpp
//  test
//
//  Created by 주성호 on 2020/07/29.
//  Copyright © 2020 주성호. All rights reserved.
//
//  https://www.acmicpc.net/problem/3036
//  BOJ3036 링 : 최대공약수

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, first;
vector<int> arr;
int gcd(int a, int b) {
    if(a < b) swap(a, b);
    return (a % b) ? gcd(b, a % b) : b;
}

int main() {
    cin >> N >> first;
    N -= 1;
    arr.resize(N);
    for(int i = 0; i < N; i++) cin >> arr[i];
    
    for(int i = 0; i < N; i++) {
        int d = gcd(first, arr[i]);
        cout << first / d << "/" << arr[i] / d << "\n";
    }
    return 0;
}
