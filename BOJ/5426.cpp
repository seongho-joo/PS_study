/** 
 * BOJ5426 - 비밀편지
*/
#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#define fastIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main() {
    fastIO();
    int N;
    cin >> N;
    
    while(N--) {
        vector<vector<char> > v;
        string str;
        cin >> str;

        int size = sqrt(str.size()); // str은 항상 제곱수
        
        auto ch = str.begin();

        v.resize(size, vector<char>(size));

        for(int i = 0; i < size; i++) {
            for(int j = 0; j < size; j++) {
                v[i][j] = *ch;
                ch++;
            }
        }

        for(int i = size - 1; i >= 0; i--) {
            for(int j = 0; j < size; j++) {
                cout << v[j][i];
            }
        }
        cout << "\n";
    }
    return 0;
}