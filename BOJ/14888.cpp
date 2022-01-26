//
//  14888.cpp
//  test
//
//  Created by 주성호 on 2022/01/26.
//  Copyright © 2022 주성호. All rights reserved.
//

#include <bits/stdc++.h>

using namespace std;

vector<int> num, numberOfOperator(4);
vector<int> op;

void insertOperator(int n, int c) {
    for (int i = 0; i < n; i++) {
        switch (c) {
            case 0:
                op.push_back(0);
                break;
            case 1:
                op.push_back(1);
                break;
            case 2:
                op.push_back(2);
                break;
            case 3:
                op.push_back(3);
                break;
        }
    }
}

void inputData() {
    int N;
    cin >> N;
    
    num.reserve(N);
    
    while (N--) {
        int n;
        cin >> n;
        num.push_back(n);
    }
    
    for (int i = 0; i < 4; i++) {
        cin >> numberOfOperator[i];
        insertOperator(numberOfOperator[i], i);
    }
}

int main() {
    inputData();
    int max_value = -INT_MAX, min_value = INT_MAX;
    do {
        int temp = num[0];
        for (int i = 1; i < num.size(); i++) {
            if (op[i - 1] == 0) {
                temp += num[i];
            } else if (op[i - 1] == 1) {
                temp -= num[i];
            } else if (op[i - 1] == 2) {
                temp *= num[i];
            } else {
                temp /= num[i];
            }
        }
        max_value = max(max_value, temp);
        min_value = min(min_value, temp);
    } while (next_permutation(op.begin(), op.end()));
    
    cout << max_value << "\n" << min_value << '\n';
    
    return 0;
}

