//
//  3005.cpp
//  test
//
//  Created by 주성호 on 2020/07/24.
//  Copyright © 2020 주성호. All rights reserved.
//
//  https://www.acmicpc.net/problem/3005
//  BOJ3005 크로스워드 퍼즐 쳐다보기 : 구현, 파싱, 문자열

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    vector<vector<char> > puzzle;
    vector<string> word;
    string str = "";
    int r, c;
    cin >> r >> c;
    puzzle.resize(r, vector<char>(c));
    
    for(int i = 0; i < r; i++)
        for(int j = 0; j < c; j++) cin >> puzzle[i][j];
    
    for(int i = 0; i < r; i++) {
        str = "";
        for(int j = 0; j < c; j++) {
            if(puzzle[i][j] == '#') {
                if(str.size() >= 2) {
                    word.push_back(str);
                    str = "";
                }
                str = "";
                continue;
            }
            str += puzzle[i][j];
        }
        if(str.size() >= 2) word.push_back(str);
    }
    
    for(int i = 0; i < c; i++) {
        str = "";
        for(int j = 0; j < r; j++) {
            if(puzzle[j][i] == '#') {
                if(str.size() >= 2) {
                    word.push_back(str);
                    str = "";
                }
                str = "";
                continue;
            }
            str += puzzle[j][i];
        }
        if(str.size() >= 2) word.push_back(str);
    }

    sort(word.begin(), word.end());
    
    cout << word[0] << "\n";
    
    return 0;
}
