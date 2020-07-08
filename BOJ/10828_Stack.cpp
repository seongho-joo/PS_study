#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

    stack<int> st;

    int T; // testcase
    cin >> T;
    while(T--) {
        string op;
        cin >> op;
        if(op.compare("push") == 0) {
            int num;
            cin >> num;
            st.push(num);
        }
        else if(op.compare("pop") == 0) {
            if(!st.empty()) {
                cout << st.top() << "\n";
                st.pop();
            }
            else
                cout << -1 << "\n";
        }
        else if(op.compare("size") == 0) {
            cout << st.size() << "\n";
        }
        else if(op.compare("empty") == 0)
            cout << st.empty() << "\n";
        else {
            if(!st.empty()) cout << st.top() << "\n";
            else cout << -1 << "\n";
        }
    }
    return 0;
}