//
//  1708.cpp
//  OnlineJudge
//
//  Created by 주성호 on 2020/06/11.
//  Copyright © 2020 주성호. All rights reserved.
//
//  https://www.acmicpc.net/problem/1708 볼록 껍질

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Point {
    int x, y, p, q;
    Point() : x(0), y(0), p(0), q(0) {}
    Point(int x, int y) : x(x), y(y), p(1), q(0) {}
    bool operator < (const Point a) const {
        if(1LL * q * a.p != 1LL * p * a.q) return 1LL * q * a.p < 1LL * p * a.q;
        if(y != a.y) return y < a.y;
        return x < a.x;
    }
};

vector<Point> p, hull;

int ccw(Point a, Point b, Point c) {
    long long ret = (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
    if(ret > 0) return 1;
    else if (ret == 0) return 0;
    else return -1;
}

void convexHull(int n) {
    sort(p.begin(), p.end());
    for(int i = 1; i < n; i++) {
        p[i].p = p[i].x - p[0].x;
        p[i].q = p[i].y - p[0].y;
    }
    sort(p.begin() + 1, p.end());
    
    hull.push_back(p[0]);
    hull.push_back(p[1]);
    int next = 2;
    
    while(next < n) {
        while(hull.size() >= 2) {
            Point f = hull.back(); hull.pop_back();
            Point s = hull.back();
            if(ccw(s, f, p[next]) > 0) {
                hull.push_back(f);
                break;
            }
        }
        hull.push_back(p[next++]);
    }
}

int main() {
    int n;
    cin >> n;
    p.resize(n);
    
    for(int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        p[i] = Point(x, y);
    }
    
    convexHull(n);
    cout << hull.size() << "\n";
    
    return 0;
}
