#include <iostream>
#include <cmath>
#include <string>
using namespace std;

int Hexadecimal(string data, int size){
    int result = 0;
    int j = 0;
    for (int i = size - 1; i >= 0; i--, j++){
        if(data[i] == 'x') break;
        switch (data[i]) {
        case 'a':
            result += 10 * pow(16, j);
            break;
        case 'b':
            result += 11 * pow(16, j);
            break;
        case 'c':
            result += 12 * pow(16, j);
            break;
        case 'd':
            result += 13 * pow(16, j);
            break;
        case 'e':
            result += 14 * pow(16, j);
            break;
        case 'f':
            result += 15 * pow(16, j);
            break;
        default:
            result += (data[i] - 48) * pow(16, j);
        }
    }
    return result;
}
int Octal(string data, int size) {
    int j = 0;
    int result = 0;
    for (int i = size - 1; i > 0; i--, j++){
        result += (data[i] - 48) * pow(8, j);
    }
    return result;
}
int main(){
    string data;
    cin >> data;
    int size = data.size();
    if(data[0] != '0') cout << data;
    else{
        if(data[1] == 'x') cout << Hexadecimal(data, size);
        else cout << Octal(data, size);
    }
    return 0;
}