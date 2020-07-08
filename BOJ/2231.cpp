/**브루트 포스 - 분해 합 */
#include <iostream>
using namespace std;

int main (){
    int num, res = 0;
    cin >> num;

    for(int i = 0; i < num; i++) {
        int temp = i, sum = i;
        while(true) {
            if(temp < 10) {
                sum += temp;
                break;
            }
            sum += temp % 10;
            temp /= 10;
        }
        if(sum == num) {
            res = i;
            break;
        }
    }
    if(res == 0) cout << 0;
    else cout << res;
    return 0;
}