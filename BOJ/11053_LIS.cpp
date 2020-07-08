#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> arr;
    vector<int> dp(N);

    arr.reserve(N);
    while(N--) {
        int num;
        cin >> num;
        arr.push_back(num);
    }

    dp[0] = 1;

    for(int i = 0; i < arr.size(); i++) {
        dp[i] = 1;
        for(int j = 0; j < i; j++) {
            if(arr[i] > arr[j] && dp[j] + 1 > dp[i]) 
                dp[i] = dp[j] + 1;
        }
    }

    cout << *max_element(dp.begin(), dp.end()) << "\n";

    return 0;
}