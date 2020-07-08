/**
 * https://www.acmicpc.net/problem/2753
 * BOJ2753 - 윤년
 */
#include <iostream>

using namespace std;

#define fastIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

bool chkLeapYear(int year) {
    if (year % 4 == 0) {
        if (year % 100 == 0 && year % 400 == 0)
            return true;
        else if (year % 100 == 0)
            return false;
        else
            return true;
    } else
        return false;
}

int main() {
    fastIO();

    int year;
    cin >> year;

    if (chkLeapYear(year))
        cout << 1 << '\n';
    else
        cout << 0 << '\n';

    return 0;
}