//
//  3023.cpp
//  OnlineJudge
//
//  Created by 주성호 on 2020/07/07.
//  Copyright © 2020 주성호. All rights reserved.
//
//  https://www.acmicpc.net/problem/3023
//  BOJ3023 마술사 이민혁 : 구현

#include <iostream>
#include <vector>
using namespace std;

int r, c, a, b;
vector<vector<char> > pattern;

void solve() {
    int y = 0, x = 0;
    for (int i = 0; i < r; i++) {
        y += 1;
        x = 0;
        for (int j = 0; j < c; j++) {
            x += 1;
            if (x == b && y == a) {
                if (pattern[i][j] == '.')
                    cout << "#";
                else
                    cout << ".";
            } else
                cout << pattern[i][j];
        }
        for (int j = c - 1; j >= 0; j--) {
            x += 1;
            if (x == b && y == a) {
                if (pattern[i][j] == '.')
                    cout << "#";
                else
                    cout << ".";
            } else
                cout << pattern[i][j];
        }
        cout << "\n";
    }
    for (int i = r - 1; i >= 0; i--) {
        y += 1;
        x = 0;
        for (int j = 0; j < c; j++) {
            x += 1;
            if (x == b && y == a) {
                if (pattern[i][j] == '.')
                    cout << "#";
                else
                    cout << ".";
            } else
                cout << pattern[i][j];
        }
        for (int j = c - 1; j >= 0; j--) {
            x += 1;
            if (x == b && y == a) {
                if (pattern[i][j] == '.')
                    cout << "#";
                else
                    cout << ".";
            } else
                cout << pattern[i][j];
        }
        cout << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> r >> c;
    pattern.resize(r, vector<char>(c));
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++) cin >> pattern[i][j];
    cin >> a >> b;
    solve();
    return 0;
}
