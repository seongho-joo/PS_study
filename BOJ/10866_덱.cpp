#include <iostream>
#include <fstream>
#include <deque>
using namespace std;

int main(){
    //ifstream inp("test.inp");
    //ofstream out("test.out");
    int T; // 경우의 수
    cin >> T;
    // inp >> T;
    deque<int> deq;
    while(T--){
        string op; int num;
        cin >> op;
        // inp >> op;
        if(op.compare("push_front") == 0) {
            cin >> num;
            // inp >> num;
            deq.push_front(num);
        }
        else if(op.compare("push_back") == 0) {
            cin >> num;
            // inp >> num;
            deq.push_back(num);
        }
        else if(op.compare("pop_front") == 0) {
            if (deq.empty())
                cout << -1 << "\n";
            else { 
                cout << deq.front() << endl;
                deq.pop_front();
            }
        }
        else if(op.compare("pop_back") == 0) { 
            if (deq.empty())
                cout << -1 << "\n";
            else { 
                cout << deq.back() << endl;
                deq.pop_back();
            }
        }
        else if(op.compare("size") == 0) cout << deq.size() << "\n";
        else if(op.compare("empty") == 0) cout << deq.empty() << "\n";
        else if(op.compare("front") == 0) {
            if(!deq.empty())
                cout << deq.front() << "\n";
            else
                cout << -1 << endl;
        }
        else if(op.compare("back") == 0) {
            if(!deq.empty())
                cout << deq.back() << "\n";
            else 
                cout << -1 << endl;
        }
    }
    // inp.close();
    // out.close();
    return 0;
}