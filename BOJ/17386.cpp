//
//  17386.cpp
//  OnlineJudge
//
//  Created by 주성호 on 2020/05/02.
//  Copyright © 2020 주성호. All rights reserved.
//
//  https://www.acmicpc.net/problem/17386 - 선분 교차 1

#include <iostream>
using namespace std;

typedef long long lint;
struct Point {
    lint x, y;
    Point(): x(0), y(0) {}
    Point(lint x, lint y): x(x), y(y) {}
};

lint ccw(Point a, Point b, Point c) {
    lint ret = (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
    if(ret > 0) return 1;
    else if(ret == 0) return 0;
    else return -1;
}

bool intersect(Point a, Point b, Point c, Point d) {
    return ccw(a, b, c) * ccw(a, b, d) < 0 && ccw(c, d, a) * ccw(c, d, b) < 0;
}

Point p[4];

int main() {
    for(int i = 0; i < 4; i++) {
        int x, y;
        cin >> x >> y;
        p[i] = Point(x, y);
    }
    
    cout << (intersectionProp(p[0], p[1], p[2], p[3]) ? 1 : 0) << "\n";
    return 0;
}
