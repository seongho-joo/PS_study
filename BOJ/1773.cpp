/**
 * https://www.acmicpc.net/problem/1773
 * BOJ1773 - 폭죽쇼
*/
#include <iostream>
#include <vector>
#define fastIO() ios_base::sync_with_stdio(false), cin.tie(), cout.tie()
using namespace std;

int main()
{
    fastIO();

    int n, c; // 학생 수, 끝나는 시간
    cin >> n >> c;

    vector<int> period(n);

    for (int i = 0; i < n; i++)
        cin >> period[i];
    int res = 0;
    for (int i = 1; i <= c; i++)
    {
        bool chk = true;
        for (int j = 0; j < n; j++)
        {
            if (i % period[j] == 0 && chk)
            {
                res++;
                chk = false;
            }
        }
    }

    cout << res;

    return 0;
}