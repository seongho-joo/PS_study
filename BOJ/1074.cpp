/**
 * https://www.acmicpc.net/problem/1074
 * BOJ1074 - Z
 * divide & conquer
 */
#include <iostream>
#include <cmath>
using namespace std;

int N, r, c, res = 0;

void Divide(int n, int i, int j)
{
    if (n == 2)
    {
        if (i == r && c == j)
        {
            cout << res;
            return;
        }
        res++;
        if (i == r && c == j + 1)
        {
            cout << res;
            return;
        }
        res++;
        if (i + 1 == r && j == c)
        {
            cout << res;
            return;
        }
        res++;
        if (i + 1 == r && j + 1 == c)
        {
            cout << res;
            return;
        }
        res++;
        return; // 찾는 좌표가 없을 때
    }
    Divide(n / 2, i, j);                 // 1사분면
    Divide(n / 2, i, j + n / 2);         // 2사분면
    Divide(n / 2, i + n / 2, j);         // 3사분면
    Divide(n / 2, i + n / 2, j + n / 2); // 4사분면
}

int main()
{

    cin >> N >> r >> c;
    N = pow(2, N);
    Divide(N, 0, 0);

    return 0;
}