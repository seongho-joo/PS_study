#include <iostream>
using namespace std;

bool isPrime(int num){
    if(num < 2) return false;
    else if(num != 2 && num % 2 == 0) return false;
    else {
        for (int i = 2; i * i <= num; i++){
            if(num % i == 0) return false;
        }
        return true;
    }
}

int main(){
    int min, max;
    cin >> min >> max;

    int sum = 0, MIN = 999999;
    for (min; min <= max; min++){
        if(isPrime(min)){
            MIN = min < MIN ? min : MIN;
            sum += min;
        }
    }
    if(sum == 0) cout << -1;
    else cout << sum << "\n" << MIN;
    return 0;
}