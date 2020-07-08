/** 
 * BOJ2444 - 별 찍기 7
 *     
    *
   ***
  *****
 *******
*********
 *******
  *****
   ***
    *
*/
#include <iostream>
#define fastIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main() {
    fastIO();
    int N;
    cin >> N;
    int MAX = 2 * N - 1;
    for (int i = 0; i < MAX; i++) {
        if(i < (2 * N -1) / 2) {
            for(int j = 0; j < N - i - 1; j++) cout << " ";
            for(int j = 0; j < 2 * i + 1; j++) cout << "*";
            cout << "\n";
        }
        else {
            for(int k = 0; k < i - (MAX / 2); k++) 
                cout << " ";
            for(int k = 0; k < 2 * (N - (i - (MAX / 2))) - 1; k++) 
                cout << "*";
            cout << "\n";
        }
    }

    return 0;
}