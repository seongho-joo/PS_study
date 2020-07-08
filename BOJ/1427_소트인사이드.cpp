#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    //ifstream inp("test.inp");
    //ofstream out("test.out");
    vector<int> res;
    string num = "Hello";
    cin >> num;

    int size = num.size();
    res.reserve(size);

    for (int i = 0; i < size; i++)
        res.push_back(num[i]);

    sort(res.begin(), res.end(), greater<int>());

    for(auto i : res) cout << i;

    //inp.close();
    //out.close();
    return 0;
}
