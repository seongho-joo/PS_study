/**
 * BOJ1476 - 날짜계산
 */
#include <iostream>
#define E_MAX 15
#define S_MAX 28
#define M_MAX 19
using namespace std;

int main() {
    int e, s, m;
    cin >> e >> s >> m;
    int year = 1;
    while(1) {
        int temp_e = ((year - 1) % E_MAX) + 1;
        int temp_s = ((year - 1) % S_MAX) + 1;
        int temp_m = ((year - 1) % M_MAX) + 1;
        if(temp_e == e && temp_s == s && temp_m == m) {
            cout << year;
            return 0;
        }
        year++;
    }
}