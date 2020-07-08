#include <iostream>
using namespace std;

int Fact(int num) {
    if(num <= 1) return 1;
    else return num * Fact(num - 1);
}

int main() {
    int num;
    scanf("%d", &num);

    printf("%d", Fact(num));
    return 0;
}