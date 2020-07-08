/**
 * BOJ5988 - 홀수일까 짝수일까
 */
#include <iostream>
#include <string>
#define fastIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main() {
    int N;
    cin >> N;

    while(N--) {
        string data;
        cin >> data;
        
        int last = data.size() - 1;
        int num = data[last] - 48;
        if(num % 2 == 0) cout << "even\n";
        else cout << "odd\n";

    }

    return 0;
}