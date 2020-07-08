/**
 * https://www.acmicpc.net/problem/1107
 * BOJ1107 - 리모컨
 */
#include <iostream>
#include <string>
#include <cmath>
#include <vector>
using namespace std;

#define fastIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define MAX 1000000
bool breakdown_button[10]; // 고장난 버튼

// 버튼이 고장났는지 확인.
bool check(int target)
{
    if (breakdown_button[target])
        return false;
    return true;
}

int solve(string goal)
{
    int n = atoi(goal.c_str()), ans = abs(n - 100);
    vector<int> target;
    for (auto i : goal)
        target.push_back(i - '0');
    for (int i = 0; i < MAX; i++)
    {
        bool flag = false;
        string current = to_string(i);
        int len = current.size();

        for (int j = 0; j < len; j++)
        {
            int value = current.at(j) - '0';
            if (!check(value))
            {
                flag = true;
                break;
            }
        }
        if (!flag)
            // 숫자 버튼 횟수 + 이동한 번호와 목표 번호와의 차이
            if (ans > abs(i - n) + len)
                ans = abs(i - n) + len;
    }
    return ans;
}

int main()
{
    fastIO();
    string n; // 목표 채널
    int num;  // 고장난 버튼의 개수
    cin >> n >> num;

    while (num--)
    {
        int inp;
        cin >> inp;
        breakdown_button[inp] = true;
    }

    cout << solve(n);

    return 0;
}