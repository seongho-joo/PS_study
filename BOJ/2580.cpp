/**
 * https://www.acmicpc.net/problem/2580
 * BOJ2580 스도쿠
 */
#include <iostream>
using namespace std;
#define fastIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

int map[9][9];
bool row[9][10], col[9][10], square[9][10];

int calculate(int y, int x) { return (y / 3) * 3 + x / 3; }

void print() {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) cout << map[i][j] << ' ';
        cout << '\n';
    }
    exit(0);
}

void sudoku(int cnt) {
    if (cnt == 81) print();

    int y = cnt / 9, x = cnt % 9;

    if (map[y][x]) {
        sudoku(cnt + 1);
    } else {
        for (int k = 1; k < 10; k++) {
            if (!row[y][k] && !col[x][k] && !square[calculate(y, x)][k]) {
                map[y][x] = k;
                row[y][k] = true, col[x][k] = true;
                square[calculate(y, x)][k] = true;
                sudoku(cnt + 1);
                map[y][x] = 0;
                row[y][k] = false, col[x][k] = false;
                square[calculate(y, x)][k] = false;
            }
        }
    }
}

int main() {
    fastIO();
    for (int i = 0; i < 9; i++)
        for (int j = 0; j < 9; j++) {
            cin >> map[i][j];
            if (map[i][j]) {
                row[i][map[i][j]] = true;
                col[j][map[i][j]] = true;
                square[calculate(i, j)][map[i][j]] = true;
            }
        }
    sudoku(0);
    return 0;
}