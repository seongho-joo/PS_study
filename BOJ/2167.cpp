/**
 * 백준 2167 - 2차원 배열의 합
 * 분류 - DP
 */
#include <iostream>
#include <vector>
using namespace std;

int N, M; // 배열의 크기
vector<vector<int> > arr;

int solution(int i, int j, int x, int y) {
    int sum = 0;
    for (int a = i; a < x; a++) {
        for(int b = j; b < y; b++) {
            sum += arr[a][b];
        }
    }
    return sum;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M;

    arr.resize(N, vector<int>(M));

    for (int i = 0; i < N; i++){
        for (int j = 0; j < M; j++) {
            int data;
            cin >> data;
            arr[i][j] = data;
        }
    }

    int K; // 부분 합의 개수
    cin >> K;
    while(K--) {
        int i, j, x, y;
        cin >> i >> j >> x >> y;
        cout << solution(i - 1, j - 1, x, y) << "\n";
    }

    return 0;
}