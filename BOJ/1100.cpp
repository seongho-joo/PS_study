/**
 * https://www.acmicpc.net/problem/1100
 * BOJ1100 - 하얀 칸
 * 탐색
 */
#include <iostream>
#define fastIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define MAX 8
using namespace std;
// 0은 흰 색, 1은 검은 색
const int chess[8][8]{
    {0, 1, 0, 1, 0, 1, 0, 1},
    {1, 0, 1, 0, 1, 0, 1, 0},
    {0, 1, 0, 1, 0, 1, 0, 1},
    {1, 0, 1, 0, 1, 0, 1, 0},
    {0, 1, 0, 1, 0, 1, 0, 1},
    {1, 0, 1, 0, 1, 0, 1, 0},
    {0, 1, 0, 1, 0, 1, 0, 1},
    {1, 0, 1, 0, 1, 0, 1, 0}};

int main()
{
    int res = 0;
    for (int i = 0; i < MAX; i++)
        for (int j = 0; j < MAX; j++)
        {
            char ch;
            cin >> ch;
            /**
             * 흰 색칸에 말이 있으면 카운트
             * 'F'는 말이 있는 칸
             */
            if (chess[i][j] == 0 && ch == 'F')
                res++;
        }
    cout << res;
}