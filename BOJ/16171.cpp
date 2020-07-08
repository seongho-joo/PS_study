/**
 * https://www.acmicpc.net/problem/16171
 * BOJ16171 - 나는 친구가 적다 (Small)
 */
#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
/**
 * 커밋 실험
 */
using namespace std;

int main() {
    ifstream inp("fcfs.inp");
    ofstream out("fcfs.out");
    string input, res;
    cin >> input >> res;
    bool chk = false;

    string::iterator it = input.begin();
    while (true) {
        if (*it >= '0' && *it <= '9') it = input.erase(it);
        if (it == input.end()) break;
        it++;
    }
    vector<int> index;
    index.reserve(res.size());
    for (int i = 0; i < res.size(); i++) {
        int in = input.find(res.at(i));
        index.push_back(in);
    }

    if (index.empty()) {
        cout << 0;
        return 0;
    }

    for (int i = 1; i < index.size(); i++)
        if (index[i - 1] + 1 != index[i]) chk = true;

    if (chk)
        cout << 0 << '\n';
    else
        cout << 1 << '\n';

    return 0;
}