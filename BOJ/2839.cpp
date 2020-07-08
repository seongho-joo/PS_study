/**설탕 배달 */
#include <iostream>
#define BIG 5
#define SMALL 3
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

    int data, result = 0;
    cin >> data;

    // 기저사례 : 3보다 작으면 3이나 5로 나눌 수 없음
    if(data < SMALL) cout << "-1";
    else {
        if(data % BIG == 0) {
            cout << data / 5;
            return 0;
        }
        int bigMax = data / 5;
        while(bigMax >= 0) {
            int tmp = data - (BIG * bigMax);
            if(tmp % SMALL == 0) {
                result = bigMax + (tmp / SMALL);
                break;
            }
            bigMax--;
        }
        if(result != 0) cout << result;
        else cout << -1;
    }
    

    return 0;
}