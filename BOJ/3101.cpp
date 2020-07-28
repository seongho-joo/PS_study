//
//  3101.cpp
//  test
//
//  Created by 주성호 on 2020/07/24.
//  Copyright © 2020 주성호. All rights reserved.
//
//  https://www.acmicpc.net/problem/3101
//  BOJ3101 토끼의 이동 : 구현

#include <iostream>
using namespace std;

typedef long long lint;
lint N, K, y = 0, x = 0;
lint edge_row[2][101010];

void init() {
    edge_row[0][0] = 1;
    edge_row[1][N - 1] = N * N;
    lint add = 2;
    for(int i = 1; i < N; i++) {
        if(i % 2 == 0) edge_row[0][i] = edge_row[0][i - 1] + 1LL;
        else {
            edge_row[0][i] = edge_row[0][i - 1] + add;
            add += 4;
        }
    }
    add = 2;
    for(lint i = N - 2; i >=0; i--) {
        if(N % 2 == 1) {
            if(i % 2 == 0) edge_row[1][i] = edge_row[1][i + 1] - 1;
            else {
                edge_row[1][i] = edge_row[1][i + 1] - add;
                add += 4;
            }
        } else {
            if(i % 2 == 1) edge_row[1][i] = edge_row[1][i + 1] - 1;
            else {
                edge_row[1][i] = edge_row[1][i + 1] - add;
                add += 4;
            }
        }
    }
}

lint left_row() {
    lint ret = 0, gap = x;
    lint dy = y + x;
    if(dy % 2 == 0) ret = edge_row[0][dy] + gap;
    else ret = edge_row[0][dy] - gap;
    return ret;
}

lint right_row() {
    lint ret = 0, gap = (N - 1) - x;
    lint dy = y - gap;
    if(N % 2 == 0) {
        if(dy % 2 == 0) ret = edge_row[1][dy] + gap;
        else ret = edge_row[1][dy] - gap;
    } else {
        if(dy % 2 == 1) ret = edge_row[1][dy] + gap;
        else ret = edge_row[1][dy] - gap;
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(0);
    cin >> N >> K;
    char dir;
    init();

    lint result = 1;

    for(int i = 0; i < K; i++) {
        cin >> dir;
        if(dir == 'U') y -= 1;
        else if(dir == 'D') y += 1;
        else if(dir == 'R') x += 1;
        else x -= 1;

        if(N - x > y) result += left_row();
        else result += right_row();
    }

    cout << result;
    return 0;
}
