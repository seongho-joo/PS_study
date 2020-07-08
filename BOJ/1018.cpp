/**
 * https://www.acmicpc.net/problem/1018
 * BOJ1018 - 체스판 다시 칠하기
 */
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

#define fastIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

vector<string> board;

string Wfirst[8] = {"WBWBWBWB", "BWBWBWBW", "WBWBWBWB", "BWBWBWBW",
                    "WBWBWBWB", "BWBWBWBW", "WBWBWBWB", "BWBWBWBW"};
string Bfirst[8] = {"BWBWBWBW", "WBWBWBWB", "BWBWBWBW", "WBWBWBWB",
                    "BWBWBWBW", "WBWBWBWB", "BWBWBWBW", "WBWBWBWB"};

int WhiteCount(int y, int x) {
    int cnt = 0;
    for (int i = y; i < y + 8; i++)
        for (int j = x; j < x + 8; j++)
            if (board[i][j] != Wfirst[i - y][j - x]) cnt++;
    return cnt;
}

int BlackCount(int y, int x) {
    int cnt = 0;
    for (int i = y; i < y + 8; i++)
        for (int j = x; j < x + 8; j++)
            if (board[i][j] != Bfirst[i - y][j - x]) cnt++;
    return cnt;
}

int main() {
    fastIO();

    int M, N;
    cin >> M >> N;

    board.resize(M);

    int res = 987654321;

    for (int i = 0; i < M; i++) cin >> board[i];

    for (int i = 0; i + 7 < M; i++)
        for (int j = 0; j + 7 < N; j++)
            res = min(res, min(WhiteCount(i, j), BlackCount(i, j)));

    cout << res << '\n';

    return 0;
}