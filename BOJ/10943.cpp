/**
 * BOJ10943 - 랜덤 게임
 */
#include <iostream>
#include <cstdlib>
using namespace std;

int main() {
    int num = rand() % 10 + 1;
    cout << num << '\n';

    return 0;
}