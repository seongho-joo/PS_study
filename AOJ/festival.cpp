//
//  festival.cpp
//  test
//
//  Created by 주성호 on 2021/06/18.
//  Copyright © 2021 주성호. All rights reserved.
//

#include <iostream>
#include <vector>
#include <stdio.h>
using namespace std;

vector<int> team;

double getCost(int L, int N) {
    double avgCost = 0.0, minValue = 987654321.0;
    for(int i = L; i <= N; i += 1) {
        for(int j = 0; j <= N - i; j += 1) {
            double sumValue = 0.0;
            for(int k = j; k < i + j; k += 1) {
                sumValue += team[k];
            }
            avgCost = sumValue / i;
            minValue = minValue < avgCost ? minValue : avgCost;
        }
    }
    return minValue;
}

int main() {
    int T, N, L;
    cin >> T;
    
    while(T--) {
        cin >> N >> L;
        team.clear();
        team.reserve(N);
        for (int i = 0; i < N; i += 1) {
            int cost;
            cin >> cost;
            team.push_back(cost);
        }
        printf("%.8lf\n", getCost(L, N));
    }
    return 0;
}
