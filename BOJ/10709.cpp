//
//  10709.cpp
//  OnlineJudge
//
//  Created by 주성호 on 2020/07/08.
//  Copyright © 2020 주성호. All rights reserved.
//
//  https://www.acmicpc.net/problem/10709
//  BOJ10709 기상캐스터 : 구현

#include <iostream>
#include <vector>
using namespace std;

vector<vector<char> > sky;
vector<vector<int> > result;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int h, w;
    cin >> h >> w;

    sky.resize(h, vector<char>(w));
    result.resize(h, vector<int>(w, -1));

    for (int i = 0; i < h; i++)
        for (int j = 0; j < w; j++) {
            cin >> sky[i][j];
            if (sky[i][j] == 'c') result[i][j] = 0;
        }

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (result[i][j] == 0) {
                for (int k = j + 1; result[i][k] != 0; k++) {
                    if (k > w - 1) break;
                    result[i][k] = result[i][k - 1] + 1;
                    j += 1;
                }
            }
        }
    }

    for (auto i : result) {
        for (int j : i) cout << j << " ";
        cout << "\n";
    }

    return 0;
}
