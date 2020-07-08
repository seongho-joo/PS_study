/**
 * https://www.acmicpc.net/problem/2609
 * BOJ2609 - 최대공약수와 최소공배수
 */
#include <algorithm>
#include <fstream>
#include <iostream>
using namespace std;

int main() {
  ifstream inp("fcfs.inp");
  int num1, num2, LCM;
  cin >> num1 >> num2;

  int GCD = 0, MIN = num1 < num2 ? num1 : num2;

  for (int i = 1; i <= MIN; i++) {
    if (num1 % i == 0 && num2 % i == 0) GCD = max(GCD, i);
  }

  for (int i = 1;; i++) {
    if (GCD * i % num1 == 0 && GCD * i % num2 == 0) {
      LCM = GCD * i;
      break;
    }
  }

  cout << GCD << "\n" << LCM;

  return 0;
}