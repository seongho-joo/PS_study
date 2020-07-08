/**
 * BOJ11365 - !밀비 급일
 */
#include <iostream>
#include <string>
#define fastIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main() {
    fastIO();
    while(true){
        string str;
        getline(cin, str);
        if(str.compare("END") == 0) {
            break;
        }
        for (int i = str.size() - 1; i >= 0; i--) {
            cout << str[i];
        }
        cout << "\n";
    }

    return 0;
}
