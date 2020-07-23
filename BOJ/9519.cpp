//
//  9519.cpp
//  test
//
//  Created by 주성호 on 2020/07/22.
//  Copyright © 2020 주성호. All rights reserved.
//
//  https://www.acmicpc.net/problem/9519
//  BOJ9519 졸려 : 구현, 반복문 

#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<string> hashM;
string str;
int n;

int getCycle() {
    string temp, ans = str;
    int cnt = 1;
    while(true) {
        temp = "";
        for(int i = 0; i < ans.size(); i++)
            if(i % 2 == 0) temp += ans[i];
        for(int i = (int)ans.length() - 1; i >= 0; i--)
            if(i % 2 == 1) temp += ans[i];
        ans = temp;
        if(temp == str) break;
        hashM.push_back(temp);
        cnt += 1;
    }
    return cnt;
}

int main() {
    cin >> n >> str;
    hashM.push_back(str);
    int cycle = getCycle();
    
    cout << hashM[n % cycle] << "\n";
    return 0;
}
