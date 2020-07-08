/**
 * BOJ5032 - 탄산 음료
 * 구현
 */
#include <iostream>
#define fastIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int e, f, c; // 가지고 있는 빈 병수, 발견한 빈 병수, 필요한 빈 병수

int main() {
    fastIO();
    cin >> e >> f >> c;

    e += f; // 가지고있는 빈 병 + 발견한 빈 병
    int newBottle = e / c, ans = newBottle; // 빈 병으로 바꾼 새 병
    e %= c; // 가지고 있는 빈 병을 새 병으로 바꾸고 남은 빈 병 수
    while(true) {
        e += newBottle; // 새 병은 다시 빈 병으로 바꿀 수 있음
        if(e >= c) {
            newBottle = e / c;
            e %= c;
            ans += newBottle;
        }
        else break;
    }
    
    cout << ans;

    return 0;
}