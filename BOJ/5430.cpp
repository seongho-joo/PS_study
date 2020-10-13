//
//  5430.cpp
//  test
//
//  Created by 주성호 on 2020/10/12.
//  Copyright © 2020 주성호. All rights reserved.
//
//  https://www.acmicpc.net/problem/5430
//  BOJ5430 AC : 구현, 자료구조, 덱

#include <iostream>
#include <deque>
#include <vector>
#include <algorithm>
#include <sstream>
#include <string>

using namespace std;

void print(deque<int> deq, int rev) {
    cout << "[";
    if(rev == 1) {
        for(int i = 0; i < deq.size(); i++) {
            cout << deq[i];
            if(i != deq.size() - 1) {
                cout << ",";
            }
        }
    } else {
        for(int i = deq.size() - 1; i >= 0; i--) {
            cout << deq[i];
            if(i != 0) {
                cout << ",";
            }
        }
    }
    cout << "]\n";
}

void init(deque<int> &deq, string arr) {
    string temp;
    // [, ] 제거
    arr.erase(arr.begin());
    arr.erase(arr.end() - 1);
    istringstream ss(arr);
    // ,를 제외한 문자열 split
    while(getline(ss, temp, ',')) {
        deq.push_back(stoi(temp));
    }
}

int main() {
    int T;
    string op, arr;
    
    cin >> T;
    while (T--) {
        bool flag = false;
        int rev = 1;
        int size = 0;
        deque<int> deq;
        cin >> op >> size >> arr;
        init(deq, arr);
        for (auto i : op) {
            if (i == 'R') {
                rev *= -1;
            } else if (i == 'D') {
                if(!deq.empty()) {
                    if (rev == 1) deq.pop_front();
                    else deq.pop_back();
                } else {
                    flag = true;
                    break;
                }
            }
        }
        if (flag) {
            cout << "error\n";
        } else {
            print(deq, rev);
        }
    }
    return 0;
}
