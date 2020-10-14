//
//  1620.cpp
//  test
//
//  Created by 주성호 on 2020/10/14.
//  Copyright © 2020 주성호. All rights reserved.
//
//  https://www.acmicpc.net/problem/1620
//  BOJ1620 나는야 포켓몬 마스터 이다솜 : 자료 구조, 트리를 사용한 집합과 맵, 해시를 사용한 집합과 맵

#include <iostream>
#include <map>
#include <string>

using namespace std;

int N, M;
map<string, int> sToI;
map<int, string> iToS;
string inp;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        cin >> inp;
        sToI[inp] = i;
        iToS[i] = inp;
    }
    while (M--) {
        cin >> inp;
        if (inp[0] >= '0' && inp[0] <= '9') {
            int n = stoi(inp);
            cout << iToS.find(n)->second << "\n";
        } else {
            cout << sToI.find(inp)->second << "\n";
        }
    }
    return 0;
}
