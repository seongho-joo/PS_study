
//
//  1193.cpp
//  test
//
//  Created by 주성호 on 2021/06/07.
//  Copyright © 2021 주성호. All rights reserved.
//

// https://www.acmicpc.net/problem/1193
// BOJ1193 분수찾기 : 수학, 구현

#include <iostream>
using namespace std;

int main() {
    int inp = 0;
    cin >> inp;
    
    if(inp == 1) {
        cout << "1/1\n";
        return 0;
    }
    int i = 1;
    int diff = 0;
    
    for(int sum = 0; sum + i < inp; i += 1) {
        sum += i;
        diff = inp - sum;
    }
    
    if(i % 2 == 1) {
        cout << i - diff + 1 << '/' << diff << "\n";
    } else {
        cout << diff << "/" << i - diff + 1 << "\n";
    }
    
    return 0;
}
