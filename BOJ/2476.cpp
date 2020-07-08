/**
 * https://www.acmicpc.net/problem/2476
 * BOJ2476 - 주사위 게임
 */
#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>
using namespace std;

int solve(vector<int>& v) {
  int answer = 0;

  sort(v.begin(), v.end());
  if (v[0] == v[1] && v[1] == v[2])
    answer = 10000 + v[0] * 1000;
  else if (v[0] == v[1] || v[0] == v[2] || v[1] == v[2]) {
    if (v[0] == v[1] || v[0] == v[2])
      answer = 1000 + v[0] * 100;
    else
      answer = 1000 + v[1] * 100;
  } else
    answer = v[2] * 100;

  return answer;
}

int main() {
  ifstream inp("fcfs.inp");
  ofstream out("fcfs.out");

  int N, MAX = 0;
  cin >> N;
  vector<int> v;
  v.reserve(N);

  while (N--) {
    for (int i = 0; i < 3; i++) {
      int data;
      cin >> data;
      v.push_back(data);
    }
    MAX = max(MAX, solve(v));
    v.clear();
  }

  cout << MAX;

  return 0;
}