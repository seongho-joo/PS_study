#include <iostream>
#include <cstring>
using namespace std;

int dp[41];

int fibonacci(int num) {
    if(num == 0) {
        dp[0] = 0;
        return 0;
    }
    else if (num == 1) {
        dp[1] = 1;
        return 1;
    }
    if(dp[num] != 0) { /**이미 계산 된 값 */
        return dp[num]; 
    }
    else {
        return dp[num] = fibonacci(num - 1) + fibonacci(num - 2);
    }
}

int main() {
    int T;
    cin >> T;

    while(T--) {
        int num;
        cin >> num;
        if(num == 0) 
            cout << "1 0\n";
        else if(num == 1)
            cout << "0 1\n";
        else {
            fibonacci(num);
            cout << dp[num - 1] << " " << dp[num] << "\n";
            memset(dp, 0, sizeof(dp));
        }
    }

    return 0;
}