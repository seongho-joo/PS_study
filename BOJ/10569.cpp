//
//  10569.cpp
//  OnlineJudge
//
//  Created by 주성호 on 2020/04/23.
//  Copyright © 2020 주성호. All rights reserved.
//
//  https://www.acmicpc.net/problem/10569
//  다면체

#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T;
    cin >> T;
    while(T--) {
        int V, E, ans = 0;
        cin >> V >> E;
        ans = 2 + E - V;
        cout << ans << '\n';
    }
    return 0;
}
