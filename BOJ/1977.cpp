//
//  1977.cpp
//  OnlineJudge
//
//  Created by 주성호 on 2020/06/15.
//  Copyright © 2020 주성호. All rights reserved.
//
//  https://www.acmicpc.net/problem/1977 완전제곱수

#include <iostream>
#include <set>
#include <cmath>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int M, N, res = 0;
    cin >> M >> N;
    set<int> s;
    for(int i = M; i <= N; i++){
        int n = (int)sqrt(i);
        if(n * n == i) {
            s.insert(i);
            res += i;
        }
    }
    if(!s.empty())
        cout << res << "\n" << *s.begin() << "\n";
    else cout << -1 << "\n";
    return 0;
}
