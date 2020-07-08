/**
 * https://www.acmicpc.net/problem/1158
 * BOJ1158 - 조세퍼스 문제
 * 전산학이나 수학에서 요세푸스 문제(Josephus problem) 혹은 요세푸스 순열(Josephus permutation)은 다음과 같이 정의한다.
 * n과 k가 자연수이고, k < n이라고 가정한다. n명이 동그랗게 모여있을 때 임의의 한 명부터 순서를 세어 k번째 사람을 모임에서 
 * 제외한다. 남은 n-1명에서 다시 다음 사람부터 순서를 세서 k번째 사람을 모임에서 제외한다. 이것을 아무도 남지 않을 때까지 
 * 계속해서 반복한다. 이때 모임에서 제외되는 사람의 순서를 (n, k) 요세푸스 순열이라고 하며 마지막으로 제외되는 
 * 사람을 구하는 문제를 요세푸스 문제라고 한다.
 * 예를 들어 (7,3) 요세푸스 순열은 {3,6,2,7,5,1,4}이며 4번째 위치한 사람이 마지막으로 제외되게 된다.
 * 이 순열은 역사가 요세푸스가 겪은 일화에서 유래하였다.
 * 출처 : https://ko.wikipedia.org/wiki/%EC%9A%94%EC%84%B8%ED%91%B8%EC%8A%A4_%EB%AC%B8%EC%A0%9C
 */
#include <iostream>
#include <queue>
#define fastIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main() {
    queue<int> josephus;
    int N, M;
    cin >> N >> M;
    for(int i = 1; i <= N; i++)
        josephus.push(i);
    cout << "<";
    while(!josephus.empty()) {
        for(int i = 0; i < M - 1; i++) {
            josephus.push(josephus.front());
            josephus.pop();
        }
        if(josephus.size() != 1)
            cout << josephus.front() << ", ";
        else cout << josephus.front();
        josephus.pop();
    }
    cout << ">";
    return 0;
}