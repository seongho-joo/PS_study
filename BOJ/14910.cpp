/**
 * https://www.acmicpc.net/problem/14910
 * BOJ14910 오르막
 */
#include <iostream>
#include <vector>
using namespace std;

/** 백준에서 실행할 때 주석처리 안하면 오작동으로 틀렸다고 뜸 */
#define fastIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
vector<long long> arr;
long long num;

bool isAscending(int len) {
    for (int i = 0; i < len - 1; i++)
        if (arr[i] > arr[i + 1]) return false;
    return true;
}

int main() {
    fastIO();

    /** 입력갯수 모르는 상황에서 입력을 받을 때 사용 */
    do {
        cin >> num;
        arr.push_back(num);
    } while (getc(stdin) == ' ');

    if (isAscending(arr.size()))
        cout << "Good";
    else
        cout << "Bad";

    return 0;
}