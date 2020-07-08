//
//  2960.cpp
//  OnlineJudge
//
//  Created by 주성호 on 2020/06/30.
//  Copyright © 2020 주성호. All rights reserved.
//
//  https://www.acmicpc.net/problem/2960 에라토스테네스의 체

#include <iostream>
#include <vector>
using namespace std;

struct Teras {
    bool prime;
    int cnt;
};
vector<Teras> num;

int main() {
    int n, k, cnt = 1, ans = 0;
    cin >> n >> k;
    num.resize(n + 1, {false, 0});
    
    for(int i = 2; i <= n; i++) {
        if(num[i].cnt == 0)
            num[i].cnt = cnt++;
        if(num[i].cnt == k) {
            ans = i;
            break;
        }
        if(!num[i].prime) {
            for(int j = i + i; j <= n; j += i) {
                if(num[j].cnt == 0) {
                    num[j].prime = true;
                    num[j].cnt = cnt++;
                    if(num[j].cnt == k) {
                        ans = j;
                        break;
                    }
                }
            }
        }
        if(ans != 0) break;
    }
    cout << ans << "\n";
    return 0;
}
