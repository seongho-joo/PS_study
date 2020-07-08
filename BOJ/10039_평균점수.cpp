#include <iostream>
#include <vector>
using namespace std;
#define MAX 5
vector<int> grade;

int main(){
    grade.reserve(MAX);
    
    int n;
    
    for (int i = 0; i < MAX; i++){
        cin >> n;
        if (n < 40) n = 40;
        grade.push_back(n);
    }

    int sum = 0;
    for (auto i : grade) sum += i;
    cout << sum / 5;

    return 0;
}