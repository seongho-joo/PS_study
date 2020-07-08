//
//  17387.cpp
//  OnlineJudge
//
//  Created by 주성호 on 2020/05/02.
//  Copyright © 2020 주성호. All rights reserved.
//
//  https://www.acmicpc.net/problem/17387 - 선분 교차 2

#include <iostream>
#include <algorithm>
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
    lint ab = ccw(a, b, c) * ccw(a, b, d);
    lint cd = ccw(c, d, a) * ccw(c, d, b);
    if(ab == 0 && cd == 0) {
        if(max(a.x, b.x) < min(c.x, d.x)) return false;
        if(min(a.x, b.x) > max(c.x, d.x)) return false;
        if(max(a.y, b.y) < min(c.y, d.y)) return false;
        if(min(a.y, b.y) > max(c.y, d.y)) return false;
        return true;
    }
//    if(ab <= 0 && cd <= 0) {
//        if(max(a.x, b.x) == min(c.x, d.x)) return false;
//        if(min(a.x, b.x) == max(c.x, d.x)) return false;
//        if(max(a.y, b.y) == min(c.y, d.y)) return false;
//        if(min(a.y, b.y) == max(c.y, d.y)) return false;
//        return true;
//    }
    return ab <= 0 && cd <= 0;
}

Point p[4];

int main() {
    for(int i = 0; i < 4; i++) {
        int x, y;
        cin >> x >> y;
        p[i] = Point(x, y);
    }
    
    cout << (intersect(p[0], p[1], p[2], p[3]) ? 1 : 0) << "\n";
    return 0;
}
