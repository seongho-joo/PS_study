/**
 * https://www.acmicpc.net/problem/11650
 * BOJ11650 - 좌표 정렬하기
 */
#include <iostream>
#include <algorithm>
#include <vector>
#define fastIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

typedef struct Coordinate {
    int x;
    int y;
}Coordinate;

bool comp(const Coordinate& x, const Coordinate& y) {
    if(x.x == y.x) return x.y < y.y;
    return x.x < y.x;
}

int main() {
    vector<Coordinate> coordinate;
    Coordinate coor;
    
    int N;
    cin >> N;
    
    while(N--) {
        cin >> coor.x >> coor.y;
        coordinate.push_back(coor);
    }
    sort(coordinate.begin(), coordinate.end(), comp);
    for(auto i : coordinate) {
        cout << i.x << " " << i.y << "\n";
    }

    return 0;
}