//
//  8979.cpp
//  OnlineJudge
//
//  Created by 주성호 on 2020/06/30.
//  Copyright © 2020 주성호. All rights reserved.
//
//  https://www.acmicpc.net/problem/8979 올림픽

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct Medal {
    int country;
    int gold, silver, bronze;
    int rank;
    Medal() : country(0), gold(0), silver(0), bronze(0), rank(0) {}
    Medal(int c, int g, int s, int b) : country(c), gold(g), silver(s), bronze(b), rank(0) {}
    bool operator < (Medal m) const {
        if(gold != m.gold) return gold > m.gold;
        if(silver != m.silver) return silver > m.silver;
        return bronze > m.bronze;
    }
};

vector<Medal> ranking;

int main() {
    int n, m;
    cin >> n >> m;
    ranking.resize(n);
    
    for(int i = 0; i < n; i++) {
        int c, g, s, b;
        cin >> c >> g >> s >> b;
        ranking[i] = Medal(c, g, s, b);
    }
    sort(ranking.begin(), ranking.end());
    ranking[0].rank = 1;
    int r = 2;
    for(int i = 1; i < n; i++) {
        ranking[i].rank = r++;
        if(ranking[i].gold == ranking[i - 1].gold && ranking[i].silver == ranking[i - 1].silver && ranking[i].bronze == ranking[i - 1].bronze) {
            ranking[i].rank = ranking[i - 1].rank;
        }
    }
    for(int i = 0; i < n; i++) {
        if(m == ranking[i].country) {
            cout << ranking[i].rank << "\n";
            break;
        }
    }
    return 0;
}
