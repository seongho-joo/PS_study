//
//  2002.cpp
//  test
//
//  Created by 주성호 on 2020/07/15.
//  Copyright © 2020 주성호. All rights reserved.
//
//  https://www.acmicpc.net/problem/2002
//  BOJ2002 추월 : 문자열 처리, 구현, 해싱

#include <iostream>
#include <vector>
#include <string>
using namespace std;

typedef pair<string, int> psi;

vector<psi> order;

int getOrder(string car, int n) {
    for(int i = 0; i < n; i++)
        if(car == order[i].first) return order[i].second;
    return -1;
}

int main() {
    string car_num;
    int n, res = 0;
    cin >> n;
    
    order.resize(n);
    
    for(int i = 0; i < n; i++) {
        cin >> car_num;
        order[i] = make_pair(car_num, i);
    }
    
    vector<int> exit(n);
    
    for(int i = 0; i < n; i++) {
        cin >> car_num;
        int idx = getOrder(car_num, n);
        exit[i] = idx;
    }
    
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            if(exit[i] > exit[j]) {
                res += 1;
                break;
            }
        }
    }
    
    cout << res << "\n";
    
    return 0;
}
