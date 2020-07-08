//
//  1159.cpp
//  OnlineJudge
//
//  Created by 주성호 on 2020/07/02.
//  Copyright © 2020 주성호. All rights reserved.
//
//  https://www.acmicpc.net/problem/1159 농구 경기

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

int main() {
    map<char, int> list;
    vector<char> result;
    string last_name;
    int n;
    cin >> n;
    
    while(n--) {
        cin >> last_name;
        list[last_name[0]] += 1;
    }
    
    for(auto m : list)
        if(m.second >= 5) result.push_back(m.first);
    
    sort(result.begin(), result.end());
    if (result.empty()) cout << "PREDAJA";
    else for(char r : result) cout << r;
    cout << "\n";
        
    return 0;
}
