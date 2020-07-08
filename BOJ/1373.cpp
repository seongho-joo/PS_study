/**
 * BOJ1373 - 2진수 8진수
 */
#include <iostream>
#include <algorithm>
#include <list>
#include <cmath>
#include <string>
using namespace std;

string binary, temp;

int Octal() {
    int octal = 0;
    for(int i = 0; i < temp.size(); i++) {
        octal += pow(2, i) * (temp[i] - 48);
    }
    return octal;
}

int main() {
    list<int> res;
    cin >> binary;
    int len = binary.size();
    /**
     * binary의 사이즈가 3의배수가 아니면
     * 0을 추가해서 3의 배수로 맞쳐줌
     */
    if(len % 3 != 0) {
        int temp = len % 3;
        switch (temp) {
        case 1:
            for(int i = 0; i < 2; i++){ 
                binary.insert(binary.begin(), '0');
            }
            break;
        case 2:
            binary.insert(binary.begin(),'0');
            break;
        }
    }
    
    for(int i = binary.size() - 1, cnt = 0; i >= -1; i--) {
        /**
         * 2진수를 0승부터 3개씩 끊어서
         * 십진수로 바꾸면 8진수로 바꿀 수 있음
         */
        if(cnt == 3) {
            cnt = 0;
            res.push_front(Octal());
            temp.clear();
        }
        temp += binary[i];
        cnt++;
    }
    for(auto i : res) cout << i;

    return 0;
}