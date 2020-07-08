/* �ϳ��� ž */
#include <iostream>
#include <cmath>
using namespace std;

void hanoi(int n, int from, int by, int to) {
    // ���� ��� : n = 1�̸� a -> b ���
    if(n == 1) {
        cout << from << " " << to << "\n";
        return;
    }
    else {
        hanoi(n - 1, from, to, by);
        cout << from << " " << to << "\n";
        hanoi(n - 1, by, from, to);
    }
}

int main () {
    int N; // ����
    cin >> N;

    /* P(N) = 2P(N-1) + 1*/
    int num = pow(2, N) - 1;
    cout << num << "\n"; //
    if(N <= 20)
        hanoi(N, 1, 2, 3);

    return 0;
}