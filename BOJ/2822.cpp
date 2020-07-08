/**
 * BOJ2822 - 점수계산
 */
#include <iostream>
#include <algorithm>
#include <vector>
#define fastIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define MAX 8
using namespace std;

vector<pair<int, int> > grade;

int main() {
    fastIO();
    grade.reserve(MAX);
    vector<int> sort_seq(5);

    for(int i = 0; i < MAX; i++) {
        int data;
        cin >> data;
        grade.push_back(make_pair(data, i + 1));
    }
    /** 점수 내림차순 정렬 */
    sort(grade.begin(), grade.end(), greater<pair<int, int> >()); 

    int sum = 0;
    for(int i = 0; i < 5; i++) {
        sum += grade[i].first;
        sort_seq[i] = grade[i].second;
    }
    /** 문제번호 오름차순 정렬 */
    sort(sort_seq.begin(), sort_seq.end());
    cout << sum << "\n";
    for(int i = 0; i < 5; i++) {
        cout << sort_seq[i] << " ";
    }

    return 0;
}