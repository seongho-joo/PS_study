//
//  5556.cpp
//  test
//
//  Created by 주성호 on 2020/07/23.
//  Copyright © 2020 주성호. All rights reserved.
//
//  https://www.acmicpc.net/problem/5556
//  BOJ556 타일 : 구현

#include <iostream>
#include <algorithm>
using namespace std;

typedef pair<int, int> pii;

int main() {
    int n, k, half;
    cin >> n >> k;
    n -= 1;
    half = n / 2;
    
    while(k--) {
        int x, y, a = 0;
        pii p, s1, e1, s2, e2;
        int color;
        cin >> x >> y;
        x -= 1; y -= 1;
        if(x > y) swap(x, y);
        
        p = make_pair(x, y);
        s1 = make_pair(x, x);
        e1 = make_pair(n - x, n - x);
        s2 = make_pair(y, y);
        e2 = make_pair(n - y, n - y);
        
        if(s1.first > e1.first) swap(s1, e1);
        if(s2.first > e2.first) swap(s2, e2);
        
        a = p.first;
        if(p.first == p.second) {
            if(n -  a < a) a = n - a;
        } else if (p.first >= s1.first && p.second >= s1.second && p.first <= e1.first && p.second <= e1.second) {
            a = s1.first;
        } else { a = s2.first; }
        
        if(a % 3 == 0) color = 1;
        else if (a % 3 == 1) color = 2;
        else color = 3;
        
        cout << color << "\n";
    }
    
    return 0;
}
