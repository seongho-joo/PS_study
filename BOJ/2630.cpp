/**
 * https://www.acmicpc.net/problem/2630
 * BOJ2630 - 색종이 만들기
 */
#include <iostream>
#include <vector>
using namespace std;
#define fastIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

int white, blue, n;
vector<vector<int> > paper;

void Input() {
    cin >> n;
    paper.resize(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) cin >> paper[i][j];
}

bool checkPaper(int y, int x, int element, int dy, int dx) {
    for (int i = y; i < dy; i++)
        for (int j = x; j < dx; j++)
            if (paper[i][j] != element) return false;
    return true;
}

void Divide(int y, int x, int dy, int dx) {
    int element = paper[y][x];
    if (checkPaper(y, x, element, dy, dx)) {
        if (element == 1)
            white += 1;
        else
            blue += 1;
    } else {
        Divide(y, x, (dy + y) / 2, (dx + x) / 2);    // 좌측상단
        Divide(y, (dx + x) / 2, (dy + y) / 2, dx);   // 우측상단
        Divide((dy + y) / 2, x, dy, (dx + x) / 2);   // 좌측하단
        Divide((dy + y) / 2, (dx + x) / 2, dy, dx);  // 우측하단
    }
}

int main() {
    fastIO();
    Input();
    Divide(0, 0, n, n);

    cout << blue << '\n' << white;

    return 0;
}