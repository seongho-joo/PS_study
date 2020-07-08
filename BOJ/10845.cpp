/**
 * BOJ10845 - 큐
 */
#include <iostream>
#include <string>
#include <queue>
#define fastIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main () {
    fastIO();
    int N;
    cin >> N;

    queue<int> que;

    while(N--) {
        string op;
        cin >> op;
        if(op.compare("push") == 0) {
            int data;
            cin >> data;
            que.push(data);
        }
        else if (op.compare("pop") == 0) {
            if(!que.empty()) {
                cout << que.front() << "\n";
                que.pop();
            }
            else {
                cout << -1 << "\n";
            }
        }
        else if (op.compare("size") == 0) {
            cout << que.size() << '\n';
        }
        else if (op.compare("empty") == 0) {
            cout << que.empty() << '\n';
        }
        else if (op.compare("front") == 0) {
            if(!que.empty()) {
                cout << que.front() << "\n";
            }
            else cout << -1 << "\n";
        }
        else if (op.compare("back") == 0){
            if(!que.empty()) cout << que.back() << '\n';
            else cout << -1 << "\n";
        }
    }
    return 0;
}