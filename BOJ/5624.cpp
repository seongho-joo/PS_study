//
//  5624.cpp
//  test
//
//  Created by 주성호 on 2020/07/14.
//  Copyright © 2020 주성호. All rights reserved.
//
//  https://www.acmicpc.net/problem/5624
//  BOJ5624 좋은 수 : 배열, 구현

#include <iostream>
using namespace std;

const int MAX = 5001;
const int sumMAX = 200001;
int N, result;
int arr[MAX];
bool visited[sumMAX * 2];

int main() {
    cin >> N;
    
    for(int i = 0; i < N; i++) cin >> arr[i];
    
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < i; j++) {
            if(visited[arr[i] - arr[j] + sumMAX]) {
                result += 1;
                break;
            }
        }
        for(int j = 0; j <= i; j++)
            visited[arr[i] + arr[j] + sumMAX] = true;
    }
    
    cout << result << "\n";
    return 0;
}
