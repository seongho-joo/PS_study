/**
 * 백준 2163 - 초콜릿 자르기
 * 분류 - DP, 수학
 */
#include <iostream>
using namespace std;

int main () {
    int N, M; // 초콜릿의 사이즈
    cin >> N >> M;
    /**
     * 점화식 N -1 * N(M - 1)
     * -> N*M - 1
     */
    cout << N*M - 1;
    return 0;
}