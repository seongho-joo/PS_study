//
//  10816.cpp
//  test
//
//  Created by 주성호 on 2020/10/09.
//  Copyright © 2020 주성호. All rights reserved.
//
//  https://www.acmicpc.net/problem/10816
//  BOJ10816 숫자 카드 2 : 자료 구조, 이분 탐색, 해시를 사용한 집합과 맵

#include <iostream>
#include <map>
using namespace std;

map<int, int> card;

int main() {
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    int n, num;
    cin >> n;
    
    while(n--) {
        cin >> num;
        if(card.count(num) == 0) {
            card.insert(make_pair(num, 1));
        } else {
            card[num] += 1;
        }
    }
    
    cin >> n;
    while(n--) {
        cin >> num;
        // [] 연산이 느려 제출하면 시간초과나기 때문에 find함수 사용
        cout << card.find(num)->second << " ";
    }
    cout << "\n";
    return 0;
}
