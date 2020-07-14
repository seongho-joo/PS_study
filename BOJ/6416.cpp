//
//  6416.cpp
//  test
//
//  Created by 주성호 on 2020/07/14.
//  Copyright © 2020 주성호. All rights reserved.
//
//  https://www.acmicpc.net/problem/6416
//  BOJ6416 트리인가? : 자료구조, 구현

#include <iostream>
#include <set>
using namespace std;

int u, v, testcase = 1, node = 0;
set<int> tree;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    while(true) {
        node = 0;
        bool termination = false;
        while(cin >> u >> v, u != 0) {
            if(u == -1 && v == -1) {
                termination = true;
                break;
            }
            tree.insert(u); tree.insert(v);
            node += 1;
        }
        if(termination) break;
        bool res = false;
        if(node == 0 || (node + 1 == tree.size())) res = true;
        cout << "Case " << testcase++ << (res ? " is a tree." : " is not a tree.") << "\n";
        tree.clear();
    }
    return 0;
}
