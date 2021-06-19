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

double solution(int L, int N) {
    double ret = 987654321.0;
    /**
     1 2 3 1 2 3
     첫번째 : (1, 2, 3), (1, 2, 3, 1), (1, 2, 3, 1, 2), (1, 2, 3, 1, 2, 3)
     두번쨰 : (2, 3, 1), (2, 3, 1, 2), (2, 3, 1, 2, 3)
     세번쨰 : (3, 1, 2), (3, 1, 2, 3)
     네번쨰 : (1, 2, 3)
     이런 식으로 풀면 3중 for문을 사용할 필요없고 간결하게 풀 수 있음
     */
    for (int i = 0, j; i <= N - L; i += 1) {
        int sum = 0, count = 1;
        
        for(j = i; j < i + L - 1; j += 1, count += 1) {
            sum += team[j];
        }
        for(; j < N; j += 1, count += 1) {
            sum += team[j];
            ret = ret < ((double)sum / count);
        }
    }
    return ret;
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
        double res = solution(L, N);
        printf("%.8lf\n", res);
    }
    return 0;
}
