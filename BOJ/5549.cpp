//
//  5549.cpp
//  test
//
//  Created by 주성호 on 2020/07/16.
//  Copyright © 2020 주성호. All rights reserved.
//
//  https://www.acmicpc.net/problem/5549
//  BOJ5549 행성 탐사 : 구현

#include <iostream>
#include <vector>
using namespace std;

typedef pair<int, int> pii;
struct Map {
    int jungle, ocean, ice;
};
int N, M, k;
Map ans;
vector<vector<Map> > map;
pii s, e;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N >> M >> k;
    map.resize(N + 1, vector<Map>(M + 1));
    
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= M; j++) {
            char a;
            cin >> a;
            map[i][j] = map[i][j - 1];
            if(a == 'J') map[i][j].jungle += 1;
            else if(a == 'O') map[i][j].ocean += 1;
            else map[i][j].ice += 1;
        }
        
        for(int j = 1; j <= M; j++) {
            map[i][j].jungle += map[i - 1][j].jungle;
            map[i][j].ocean += map[i - 1][j].ocean;
            map[i][j].ice += map[i - 1][j].ice;
        }
    }
    
    for(int i = 0; i < k; i++) {
        cin >> s.first >> s.second >> e.first >> e.second;
        ans.jungle = map[e.first][e.second].jungle - map[s.first - 1][e.second].jungle - map[e.first][s.second - 1].jungle + map[s.first - 1][s.second - 1].jungle;
        ans.ocean = map[e.first][e.second].ocean - map[s.first - 1][e.second].ocean - map[e.first][s.second - 1].ocean + map[s.first - 1][s.second - 1].ocean;
        ans.ice = map[e.first][e.second].ice - map[s.first - 1][e.second].ice - map[e.first][s.second - 1].ice + map[s.first - 1][s.second - 1].ice;
        cout << ans.jungle << " " << ans.ocean << " " << ans.ice << "\n";
    }
    
    return 0;
}
