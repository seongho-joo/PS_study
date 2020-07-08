//
//  5533.cpp
//  OnlineJudge
//
//  Created by 주성호 on 2020/07/01.
//  Copyright © 2020 주성호. All rights reserved.
//
//  https://www.acmicpc.net/problem/5533 유니크

#include <iostream>
#include <vector>
using namespace std;

vector<int> check(101, 0), score;
vector<vector<int> > game;

int main() {
    int n;
    cin >> n;
    score.resize(n, 0);
    game.resize(n, vector<int>(3));
    
    for(int i = 0; i < n; i++)
        for(int j = 0; j < 3; j++) cin >> game[i][j];
    
    for(int i = 0; i < 3; i++) {
        fill(check.begin(), check.end(), 0);
        for(int j = 0; j < n; j++)
            check[game[j][i]] += 1;
        for(int j = 0; j < n; j++) {
            if(check[game[j][i]] == 1) score[j] += game[j][i];
            else score[j] += 0;
        }
    }
    
    for(int i : score) cout << i << "\n";
    
    return 0;
}
