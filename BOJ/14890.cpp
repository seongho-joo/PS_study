/**
 * https://www.acmicpc.net/problem/14890
 * BOJ14890 - 경사로
 */
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

#define fastIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

struct Incline {
    int h;
    bool chk;  // 경사로가 설치됐는지 체크
};

vector<vector<Incline> > map;
// 올라가는 경사로 설치가능한지 판단
bool isUphillInstall(int i, int j, int len, int type) {
    int temp = j - len;
    if ((j == 0 && len != 1) || temp <= -2) return false;
    // 높이차이가 1인 경우에만 경사로를 설치가능 유무판단 가능
    switch (type) {
        case 1:  // 가로
            if (len == 1) {
                if (map[i][j].chk)
                    return false;
                else
                    return true;
            }
            for (int k = j; k > temp + 1; k--)
                if ((map[i][k].h != map[i][k - 1].h) || map[i][k].chk ||
                    map[i][k - 1].chk)
                    return false;
            for (int k = j; k > temp; k--) map[i][k].chk = true;
            break;
        default:  // 세로
            if (len == 1) {
                if (map[j][i].chk)
                    return false;
                else
                    return true;
            }
            for (int k = j; k > temp + 1; k--)
                if ((map[k][i].h != map[k - 1][i].h) || map[k][i].chk ||
                    map[k - 1][i].chk)
                    return false;
            for (int k = j; k < temp; k++) map[k][i].chk = true;
            break;
    }

    return true;
}
// 내려가는 경사로 설치가능한지 판단
bool isDownphillInstall(int i, int j, int len, int n, int type) {
    int temp = j + len;
    if ((j == n && len != 1) || temp > n) return false;
    switch (type) {
        case 1:  // 가로
            for (int k = j; k < temp - 1; k++)
                if ((map[i][k].h != map[i][k + 1].h) || map[i][k].chk ||
                    map[i][k + 1].chk)
                    return false;
            for (int k = j; k < temp; k++) map[i][k].chk = true;
            break;
        default:  // 세로
            for (int k = j; k < temp - 1; k++)
                if ((map[k][i].h != map[k + 1][i].h) || map[k][i].chk ||
                    map[k + 1][i].chk)
                    return false;
            for (int k = j; k < temp; k++) map[k][i].chk = true;
            break;
    }

    return true;
}
int solution(int n, int len) {
    int ans = 0, count = 0;
    bool flag = true;
    // 가로방향
    for (int i = 0; i < n; i++) {
        flag = true;
        count = 0;
        for (int j = 0; j < n - 1; j++) {
            // 높이가 같을 경우
            if (map[i][j].h == map[i][j + 1].h)
                count += 1;
            else if (abs(map[i][j].h - map[i][j + 1].h) != 1) {
                flag = false;
                break;
            }
            // 올라가는 경사로 설치 판단
            else if (map[i][j].h < map[i][j + 1].h)
                flag = isUphillInstall(i, j, len, 1);
            // 내려가는 경사로 설치 판단
            else {
                flag = isDownphillInstall(i, j + 1, len, n, 1);
                j += len - 1;
            }
            if (!flag) break;
        }
        if (count == n - 1)
            ans += 1;  // 모든 높이가 같은경우
        else if (flag)
            ans += 1;
    }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) map[i][j].chk = false;
    // 세로방향
    for (int i = 0; i < n; i++) {
        flag = true;
        count = 0;
        for (int j = 0; j < n - 1; j++) {
            // 높이가 같을 경우
            if (map[j][i].h == map[j + 1][i].h)
                count += 1;
            else if (abs(map[j][i].h - map[j + 1][i].h) != 1) {
                flag = false;
                break;
            }
            // 올라가는 경사로 설치 판단
            else if (map[j][i].h < map[j + 1][i].h)
                flag = isUphillInstall(i, j, len, 2);
            // 내려가는 경사로 설치 판단
            else
                flag = isDownphillInstall(i, j + 1, len, n, 2);
            if (!flag) break;
        }
        if (count == n)
            ans++;
        else if (flag)
            ans++;
    }
    return ans;
}

int main() {
    fastIO();

    int N, len;  // map의 크기와 경사로 길이
    cin >> N >> len;

    map.resize(N, vector<Incline>(N));

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++) cin >> map[i][j].h;

    cout << solution(N, len);

    return 0;
}