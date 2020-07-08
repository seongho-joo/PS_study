/**
 * https://www.acmicpc.net/problem/9507
 * BOJ9507 - Generations of Tribbles
 */
#include <iostream>
#include <vector>
using namespace std;

#define fastIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
vector<long long> cache;

long long koong(int n)
{
    if (n < 2)
        return 1;
    if (n == 2)
        return 2;
    if (n == 3)
        return 4;

    long long &ret = cache[n];
    if (ret != -1)
        return ret;

    return ret = koong(n - 1) + koong(n - 2) + koong(n - 3) + koong(n - 4);
}

int main()
{
    fastIO();
    int N, input; // testcase
    cin >> N;

    while (N--)
    {
        cin >> input;
        cache.resize(input + 1, -1);
        cout << koong(input) << '\n';
        cache.clear();
    }

    return 0;
}