/**
 * https://www.acmicpc.net/problem/7785
 * BOJ7785 - 회사에 있는 사람
 */
#include <iostream>
#include <set>
#include <string>
using namespace std;

#define fastIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
set<string, greater<string> > log;

int main() {
    fastIO();
    int N;
    cin >> N;

    while (N--) {
        string name, Log;
        cin >> name >> Log;
        if (Log == "enter")
            log.insert(name);
        else
            log.erase(name);
    }

    for (set<string>::iterator it = log.begin(); it != log.end(); it++)
        cout << *it << '\n';

    return 0;
}