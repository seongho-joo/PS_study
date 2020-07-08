/** 
 * BOJ2442 - 별 찍기 5
 * for문 사용
*/
#include <iostream>
#define fastIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main() {
    fastIO();
    int N; // line 수
    cin >> N;
    int max = 2 * N -1;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N - i - 1; j++) cout << " ";
        for(int j = 0; j < 2 * i + 1; j++) cout << "*";
        cout << '\n';
    }

    return 0;
}