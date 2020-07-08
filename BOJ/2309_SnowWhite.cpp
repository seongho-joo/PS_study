#include <iostream>
#include <algorithm>
#include <vector>
#define MAX 9
using namespace std;
vector<int> v;

void solution(int sum) {
    vector<int>::iterator it, jt;
    int sub = sum - 100;
    for(it = v.begin(); it != v.end(); it++) {
        int tmp = *it;
       for(jt = it + 1; jt != v.end(); jt++) {
           if(sub == tmp + *jt) {
               v.erase(it);
               v.erase(jt - 1);
               return;
           }
       }
    }
}

int main() {
    int num, sum = 0;

    for(int i = 0; i < MAX; i++) {
        cin >> num;
        v.push_back(num);
        sum += num;
    }

    sort(v.begin(), v.end());
    solution(sum);
    for(auto i : v) cout << i << "\n";

    return 0;
}