/**
 * https://www.acmicpc.net/problem/1992
 * BOJ1992 - 쿼드트리
 * Divide & Conquer
 */
#include <iostream>
#include <string>
#include <vector>
#define fastIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

vector<vector<char>> quadTree;

// cur과 quadTree[i][j] 같은 지 판별
bool quadtreeChk(int n, int x, int y, char cur)
{
    bool chk = true;
    for (int i = y; i < y + n; i++)
        for (int j = x; j < x + n; j++)
            if (quadTree[i][j] != cur)
                return false;
    return chk;
}

void divide(int n, int x, int y)
{
    char cur = quadTree[y][x];
    if (quadtreeChk(n, x, y, cur))
        cout << cur;
    // 일치하지 않았을 때 4개로 분할
    else
    {
        cout << "(";
        divide(n / 2, x, y);
        divide(n / 2, x + n / 2, y);
        divide(n / 2, x, y + n / 2);
        divide(n / 2, x + n / 2, y + n / 2);
        cout << ")";
    }
}

int main()
{
    fastIO();
    int N; // array size
    cin >> N;

    quadTree.resize(N, vector<char>(N));

    for (int x = 0; x < N; x++)
        for (int y = 0; y < N; y++)
            cin >> quadTree[x][y];
    divide(N, 0, 0);
    return 0;
}