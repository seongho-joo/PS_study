//
//  14500.cpp
//  test
//
//  Created by 주성호 on 2020/08/25.
//  Copyright © 2020 주성호. All rights reserved.
//
//  https://www.acmicpc.net/problem/14500
//  BOJ14500 테트로미노 : 구현, 브루트포스 알고리즘

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, M;
int res = 0;
vector<vector<int> > v;

void shape1();
void shape2();
void shape3();
void shape4();
void shape5();

int main() {
    cin >> N >> M;
    v.resize(N, vector<int>(M));
    
    for(int i = 0; i < N; i++)
        for(int j = 0; j < M; j++) cin >> v[i][j];
    
    shape1();
    shape2();
    shape3();
    shape4();
    shape5();
    
    cout << res << "\n";
    
    return 0;
}

void shape1() {
    int sum = 0;
    //  ㅡ 모양 테트로미노
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            sum = 0;
            if(j + 3 <= M - 1) {
                for(int k = j; k < j + 4; k++) sum += v[i][k];
            }
            res = max(sum, res);
        }
    }
    // | 모양 테트로미노
    for(int i = 0; i < M; i++) {
        for(int j = 0; j < N; j++) {
            sum = 0;
            if(j + 3 <= N - 1) {
                for(int k = j; k < j + 4; k++) sum += v[k][i];
            }
            res = max(sum, res);
        }
    }
}

void shape2() {
    // ㅁ 모양 테트로미노
    int sum = 0;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            sum = 0;
            if(i + 1 <= N - 1 && j + 1 <= M - 1) {
                for(int k = i; k < i + 2; k++) {
                    for (int l = j; l < j + 2; l++) {
                        sum += v[k][l];
                    }
                }
            }
            res = max(sum, res);
        }
    }
}

void shape3() {
    int sum = 0;
    
    for(int i = 0; i < M; i++) {
        for(int j = 0; j < N; j++) {
            sum = 0;
            if(i != M - 1 && j + 2 <= N - 1) {
                sum = v[j][i + 1];
                for(int k = j; k < j + 3; k++) sum += v[k][i];
            }
            res = max(sum, res);
        }
    }
    
    for(int i = 1; i < M; i++) {
        for(int j = 0; j < N; j++) {
            sum = 0;
            if(j + 2 <= N - 1) {
                sum = v[j][i - 1];
                for(int k = j; k < j + 3; k++) sum += v[k][i];
            }
            res = max(sum, res);
        }
    }
    
    for(int i = 1; i < N; i++) {
        for(int j = 0; j < M; j++) {
            sum = 0;
            if(j + 2 <= M - 1) {
                sum = v[i - 1][j];
                for(int k = j; k < j + 3; k++) sum += v[i][k];
            }
            res = max(sum, res);
        }
    }
    
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            sum = 0;
            if(i != N - 1 && j + 2 <= M - 1) {
                sum = v[i + 1][j];
                for(int k = j; k < j + 3; k++) sum += v[i][k];
            }
            res = max(sum, res);
        }
    }
    
    for(int i = 1; i < M; i++) {
        for(int j = 0; j < N; j++) {
            sum = 0;
            if(j + 2 <= N - 1) {
                sum = v[j + 2][i - 1];
                for(int k = j; k < j + 3; k++) sum += v[k][i];
            }
            res = max(sum, res);
        }
    }
    
    for(int i = 0; i < M; i++) {
        for(int j = 0; j < N; j++) {
            sum = 0;
            if(i != M - 1 && j + 2 <= N - 1) {
                sum = v[j + 2][i + 1];
                for(int k = j; k < j + 3; k++) sum += v[k][i];
            }
            res = max(sum, res);
        }
    }
    
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            sum = 0;
            if(i != N - 1 && j + 2 <= M - 1) {
                sum = v[i + 1][j + 2];
                for(int k = j; k < j + 3; k++) sum += v[i][k];
            }
            res = max(sum, res);
        }
    }
    for(int i = 1; i < N; i++) {
        for(int j = 0; j < M; j++) {
            sum = 0;
            if(j + 2 <= M - 1) {
                sum = v[i - 1][j + 2];
                for(int k = j; k < j + 3; k++) sum += v[i][k];
            }
            res = max(sum, res);
        }
    }
}

void shape4() {
    int sum = 0;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            sum = 0;
            if(j != M - 1 && i + 1 < N - 1) {
                sum = v[i][j] + v[i + 1][j] + v[i + 1][j + 1] + v[i + 2][j + 1];
            }
            res = max(res, sum);
        }
    }
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            sum = 0;
            if(i != N - 1 && j + 1 < M - 1) {
                sum = v[i][j] + v[i][j + 1] + v[i + 1][j + 1] + v[i + 1][j + 2];
            }
            res = max(res, sum);
        }
    }
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            sum = 0;
            if(i != N - 1 && j - 2 >= 0) {
                sum = v[i][j] + v[i][j - 1] + v[i + 1][j - 1] + v[i + 1][j - 2];
            }
            res = max(res, sum);
        }
    }
    
    for(int i = 0; i < N; i++) {
        for(int j = 1; j < M; j++) {
            sum = 0;
            if(i + 2 <= N - 1) {
                sum = v[i][j] + v[i + 1][j] + v[i + 1][j - 1] + v[i + 2][j - 1];
            }
            res = max(res, sum);
        }
        
    }
}

void shape5() {
    int sum = 0;
    for(int i = 0; i < M; i++) {
        for(int j = 0; j < N; j++) {
            sum = 0;
            if(i != M - 1 && j + 2 <= N - 1) {
                sum += v[j + 1][i + 1];
                for(int k = j; k < j + 3; k++) sum += v[k][i];
            }
            res = max(res, sum);
        }
    }
    
    for(int i = 0; i < M; i++) {
        for(int j = 0; j < N; j++) {
            sum = 0;
            if(i != 0 && j + 2 <= N - 1) {
                sum += v[j + 1][i - 1];
                for(int k = j; k < j + 3; k++) sum += v[k][i];
            }
            res = max(res, sum);
        }
    }
    
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            sum = 0;
            if(i != N - 1 && j + 2 <= M - 1) {
                sum += v[i + 1][j + 1];
                for(int k = j; k < j + 3; k++) sum += v[i][k];
            }
            res = max(res, sum);
        }
    }
    
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            sum = 0;
            if(i != 0 && j + 2 <= M - 1) {
                sum += v[i - 1][j + 1];
                for(int k = j; k < j + 3; k++) sum += v[i][k];
            }
            res = max(res, sum);
        }
    }
}
