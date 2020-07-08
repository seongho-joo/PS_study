/**
 * https://www.acmicpc.net/problem/1929
 * BOJ1929 - 소수 구하기
 */
#include <iostream>
#include <vector>
using namespace std;

#define fastIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

vector<bool> num;

void solve(int n,int m) {
    num[0] = true;
    num[1] = true;
    
    for (int i = 2; i <= n; i++)
        if (!num[i])
            for (int j = i + i; j <= n; j += i) num[j] = true;

    for(int i = m; i < num.size(); i++) 
        if(!num[i]) cout << i << '\n';
}

int main() {
    fastIO();

    int M, N;
    cin >> M >> N;
    num.resize(N + 1, false);

    solve(N, M);

    return 0;
}