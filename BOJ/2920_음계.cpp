#include <iostream>
#include <vector>
using namespace std;

vector<int> v;

int sortCheck(){
    int asc = 0, desc = 0;
    for (int i = 0;i<7;i++) {
        if(v[i] < v[i+1]) asc++;
        else if(v[i]> v[i+1]) desc++;
    }
    if(asc == 7) return 1;
    else if(desc == 7) return 2;
    else return 0;
}

int main(){
    
    v.reserve(8);
    int n = 0;
    
    for (int i = 0; i < 8; i++){
        cin >> n;
        v.push_back(n);
    }

    if(sortCheck() == 1) cout<< "ascending\n";
    else if(sortCheck() == 2) cout << "descending\n";
    else cout << "mixed\n";

    return 0;
}