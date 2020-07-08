#include <iostream>
using namespace std;

int Fibonacci(int n){
    if(n < 2) return n;
    return Fibonacci(n - 1) + Fibonacci(n - 2);
}

int main(){
    int num;
    cin >> num;

    cout << Fibonacci(num);

    return 0;
}