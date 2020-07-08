#include <iostream>
#define MAX 4
using namespace std;

int main() {
    int num, count = 0, r = 3;

    while (r--) {
        for (int i = 0; i < MAX; i++) {
            cin >> num;
            if(num == 0) count++;
        }
        switch(count) {
            case 0: cout << "E\n"; break;
            case 1: cout << "A\n"; break;
            case 2: cout << "B\n"; break;
            case 3: cout << "C\n"; break;
            case 4: cout << "D\n"; break;
        }
        count = 0;
    }
    return 0;
}