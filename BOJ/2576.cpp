/**
 * BOJ2576 - 홀수
 */
#include <iostream>
#include <vector>
#define fastIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define MAX 7
#define INF 987654321
using namespace std;

void ODD(vector<int>& arr) {
    int sum = 0, min = INF;
    for(auto i : arr) {
        if(i % 2 == 1) {
            sum += i;
            min = min > i ? i : min;
        }
    }
    if(min != INF)
        cout << sum << "\n" << min;
    else cout << -1;
}

int main () {
    fastIO();
    vector<int> arr;
    arr.reserve(MAX);

    for(int i = 0; i < MAX; i++) {
        int data;
        cin >> data;
        arr.push_back(data);
    }

    ODD(arr);

    return 0;
}