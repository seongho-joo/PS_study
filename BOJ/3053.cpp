/**
 * https://www.acmicpc.net/problem/3053
 * BOJ3053 - 택시 기하학
 */
#include <cmath>
#include <iostream>
using namespace std;

#define fastIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

double EuclideanGeometry(int r) { return M_PI * pow(r, 2); }
double TaxiGeometry(int r) { return pow(r * 2, 2) / 2; }

int main() {
    fastIO();

    int r;
    cin >> r;

    cout << fixed;
    cout.precision(6);
    cout << EuclideanGeometry(r) << '\n';
    cout << TaxiGeometry(r) << '\n';

    return 0;
}