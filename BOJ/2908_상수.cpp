#include <iostream>
using namespace std;

int swap(int num){
    int res = 0;
    for(int i = 0;i<3;i++){
        res += num%10;
        res *= 10; num /= 10;
    }
    return res / 10;
}

int main(){
    int num1, num2;
    cin >> num1 >> num2;
    num1 = swap(num1);
    num2 = swap(num2);

    int max = num1 < num2 ? num2 : num1;
    cout << max << "\n";
    return 0;
}