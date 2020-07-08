//
//  6588.cpp
//  OnlineJudge
//
//  Created by 주성호 on 2020/06/30.
//  Copyright © 2020 주성호. All rights reserved.
//
//  https://www.acmicpc.net/problem/6588 골드바흐의 추측

#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

const int MAX = 1000001;
vector<bool> prime(MAX);

void getPrimeNumber() {
    for(int i = 2; i <= sqrt(MAX); i++) {
        if (!prime[i]) {
            for(int j = i + i; j <= MAX; j += i) prime[j] = true;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    getPrimeNumber();
    int a, b;
    int n = -1;
    while(cin >> n, n != 0) {
        for(a = 3; a <= n - 1; a++) {
            if(!prime[a]) {
                b = n - a;
                if(!prime[b]) {
                    cout << n << " = " << a << " + " << b << "\n";
                    break;
                }
            }
        }
        if(a == n) cout << "Goldbach's conjecture is wrong.\n";
    }
    return 0;
}
