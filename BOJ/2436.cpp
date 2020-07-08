//
//  2436.cpp
//  OnlineJudge
//
//  Created by 주성호 on 2020/05/30.
//  Copyright © 2020 주성호. All rights reserved.
//
//  https://www.acmicpc.net/problem/2436 공약수

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct Pair{
    long long x, y;
    long long sum;
    bool operator<(const Pair& a) const {
        return sum < a.sum;
    }
};
vector<Pair> v;
long long n, m;

long long gcd(long long a, long long b) {
    if(a < b) swap(a, b);
    if(b == 0) return a;
    return gcd(b, a % b);
}

void solve(int i) {
    while(true) {
        if(m % i == 0) {
            Pair p;
            p.x = n * i;
            p.y = m / i;
            p.sum = p.x + p.y;
            if(p.x > p.y) break;
            if(gcd(p.x, p.y) == n) v.push_back(p);
        }
        i++;
    }
}

int main() {
    cin >> n >> m;
    solve(1);
    sort(v.begin(), v.end());
    cout << v[0].x << " " << v[0].y << "\n";
    return 0;
}
