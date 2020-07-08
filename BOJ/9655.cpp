/**
 * https://www.acmicpc.net/problem/9655
 * BOJ9655 돌 게임
 */
#include <iostream>
using namespace std;

#define fastIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define MAX 101

int N;

int main() {
    fastIO();

    cin >> N;
    /**
     * 돌을 1개 또는 3개 가져갈 수 있기 때문에
     * 짝수일 때는 창영이 승 홀수일 때는 상근이가 이기게 된다.
     * */
    if (N % 2 == 1)
        cout << "SK\n";
    else
        cout << "CY\n";

    return 0;
}