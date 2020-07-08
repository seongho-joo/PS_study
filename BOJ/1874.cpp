/** 
 * BOJ1874 - 스택 수열
*/
#include <iostream>
#include <vector>
#include <string>
#include <stack>
#define fastIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

vector<int> seq; // 주어진 데이터의 수열
stack<int> st;
string res;

void solution(int N) {
    auto it = seq.begin();
    for(int i = 1; i <= N;) {
        st.push(i++);
        res.push_back('+');
        while (st.top() == *it) {
            st.pop(); 
            it++;
            res.push_back('-');
            if(st.empty()) break;
        }
    }
    if(st.empty()) { // 주어진 수열을 만들 수 있을 시
        for(auto i : res) {
            cout << i << "\n";
        }
    }
    else { // 주어진 수열을 못 만들 시
        cout << "NO";
    }
}

int main () {
    fastIO();
    int N;
    cin >> N;

    for(int i = 0; i < N; i++) {
        int data;
        cin >> data;
        seq.push_back(data);
    }

    solution(N);

    return 0;
}