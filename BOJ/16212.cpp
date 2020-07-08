/**  
 * BOJ - 16212
 * stl을 사용해서 정렬하는 문제
*/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    vector<int> arr;
    int T ;
    cin >> T;
    arr.reserve(T);
    while(T--) {
        int num;
        cin >> num;
        arr.push_back(num);
    }

    sort(arr.begin(), arr.end());

    for(auto i : arr) {
        cout << i << " ";
    }

    return 0;
}