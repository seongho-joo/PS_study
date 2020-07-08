/**
 * https://www.acmicpc.net/problem/11022
 * BOJ11022 - A+B - 8
 */
#include <iostream>
using namespace std;

#define fastIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

int main() {
  fastIO();
  int T;
  cin >> T;

  for (int i = 0; i < T; i++) {
    int a, b;
    cin >> a >> b;
    cout << "Case #" << i + 1 << ": " << a << " + " << b << " = " << a + b
         << "\n";
  }

  return 0;
}