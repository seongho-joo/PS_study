//
//  3486.cpp
//  test
//
//  Created by 주성호 on 2020/07/14.
//  Copyright © 2020 주성호. All rights reserved.
//
//  https://www.acmicpc.net/problem/3486
//  BOJ3486 Adding Reversed Numbers : 그리디 알고리즘, 수학, 구현

#include <iostream>
using namespace std;

int reverse(int n) {
    int ret = 0;
    while(n != 0) {
        ret *= 10;
        ret += n % 10;
        n /= 10;
    }
    return ret;
}

int main() {
    int T;
    cin >> T;
    
    while(T--) {
        int a, b, ans;
        cin >> a >> b;
        a = reverse(a);
        b = reverse(b);
        ans = reverse(a + b);
        cout << ans << "\n";
    }
    
    return 0;
}
