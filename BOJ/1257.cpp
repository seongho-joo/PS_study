//
//  1257.cpp
//  OnlineJudge
//
//  Created by 주성호 on 2020/06/15.
//  Copyright © 2020 주성호. All rights reserved.
//
//  https://www.acmicpc.net/problem/1275 커피숍2

#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

typedef long long lint;
vector<lint> arr, tree;
/** 펜윅트리 구현 */
void update(int idx, lint val) {
    while(idx < tree.size()) {
        tree[idx] += val;
        idx += (idx & -idx);
    }
}

lint sum(int idx) {
    lint res = 0;
    while(idx > 0) {
        res += tree[idx];
        idx -= (idx & -idx);
    }
    return res;
}

lint query(int l, int r) {
    if(l > r) swap(l, r);
    return sum(r) - sum(l - 1);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, q;
    cin >> n >> q;
    arr.resize(n + 1); tree.resize(n + 1);
    
    for(int i = 1; i < n + 1; i++) {
        cin >> arr[i];
        update(i, arr[i]);
    }
    
    for(int i = 0; i < q; i++) {
        int x = 0, y = 0, a = 0;
        lint b = 0;
        cin >> x >> y >> a >> b;
        cout << query(x, y) << "\n";
        lint diff = b - arr[a];
        arr[a] = b;
        update(a, diff);
    }
    
    return 0;
}

/** 세그먼트 트리 구현 */
//lint init(int s, int e, int idx) {
//    if(s == e) return tree[idx] = arr[s];
//    int mid = (s + e) / 2;
//    return tree[idx] = init(s, mid, idx * 2 + 1) + init(mid + 1, e, idx * 2 + 2);
//}
//
//lint query(int idx, int s, int e, int l, int r) {
//    if(r < s || e < l) return 0;
//    if(l <= s && e <= r) return tree[idx];
//    else {
//        int mid = (s + e) / 2;
//        return query(idx * 2 + 1, s, mid, l, r) + query(idx * 2 + 2, mid + 1, e, l, r);
//    }
//}
//
//void update(int idx, int s, int e, lint diff, int node) {
//    if(node < s || node > e) return;
//
//    tree[idx] += diff;
//    if(s != e) {
//        int mid = (s + e) / 2;
//        update(idx * 2 + 1, s, mid, diff, node);
//        update(idx * 2 + 2, mid + 1, e, diff, node);
//    }
//}
//
//int main() {
//    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
//    int n, q;
//    cin >> n >> q;
//
//    int tree_size, h = (int)ceil(log2(n));
//    tree_size = 1 << (h + 1);
//    arr.resize(n);
//    tree.resize(tree_size);
//
//    for(int i = 0; i < n; i++) cin >> arr[i];
//    init(0, n - 1, 0);
//    for(int i = 0; i < q; i++) {
//        int l, r, a;
//        lint k, diff;
//        cin >> l >> r >> a >> k;
//        if(l > r) swap(l, r);
//        cout << query(0, 0, n - 1, l - 1, r - 1) << "\n";
//        diff = k - arr[a - 1];
//        arr[a - 1] = k;
//        update(0, 0, n - 1, diff, a - 1);
//    }
//
//    return 0;
//}
