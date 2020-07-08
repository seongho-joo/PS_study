//
//  1764.cpp
//  OnlineJudge
//
//  Created by 주성호 on 2020/07/01.
//  Copyright © 2020 주성호. All rights reserved.
//
//  https://www.acmicpc.net/problem/1764 듣보잡

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

int main() {
    map<string, int> M;
    vector<string> v;
    
    int n, m;
    cin >> n >> m;
    string str;
    
    while(n--) {
        cin >> str;
        M[str] += 1;
    }
    
    while(m--) {
        cin >> str;
        M[str] += 1;
    }
    
    for(auto iter : M) if(iter.second != 1) v.push_back(iter.first);
    
    cout << v.size() << "\n";
    sort(v.begin(), v.end());
    
    for(string s : v) cout << s << "\n";
    
    return 0;
}
