#include <iostream>
using namespace std;

bool isPrime(int n){
    if (n < 2)
        return false;
    else{
        for (int i = 2; i * i <= n; i++)
            if (n % i == 0)
                return false;
        return true;
    }
}

int main(){
    int N, num, count = 0;
    cin >> N;

    for (int i = 0; i < N; i++){
        cin >> num;
        if(isPrime(num)) count++;
    }

    cout << count << "\n";

    return 0;
}