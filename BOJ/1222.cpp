//
//  1222.cpp
//  test
//
//  Created by 주성호 on 2020/07/22.
//  Copyright © 2020 주성호. All rights reserved.
//
//  https://www.acmicpc.net/problem/1222
//  BOJ1222 홍준 프로그래밍 대회 : 구현, 배열

#include <iostream>
#include <algorithm>
using namespace std;

const int MAX = 2000001;
typedef long long lint;
lint arr[MAX], x, res, N;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N;
    for(int i = 0; i < N; i++) {
        cin >> x;
        arr[x] += 1;
    }
    
    for(int i = 1; i < MAX; i++) {
        lint cnt = 0;
        for(int j = i; j < MAX; j += i) cnt += arr[j];
        if(cnt > 1) res = max(res, i * cnt);
    }
    cout << res << "\n";
    return 0;
}
