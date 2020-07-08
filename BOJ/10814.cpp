/** 
 * BOJ10814 - 나이순 정렬
*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#define fastIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

typedef struct Inform {
    int age;
    string name;
    int seq; // 가입한 순서
}Inform;
vector<Inform> v;

bool comp(const Inform& x, const Inform& y) {
    if(x.age == y.age) return x.seq < y.seq; // 나이가 같을 시 가입 순서로 정렬
    return x.age < y.age;
}

int main() {
    fastIO();
    Inform in;
    int N;
    cin >> N;

    for(int i = 1; i <= N; i++) {
        cin >> in.age >> in.name;
        in.seq = i;
        v.push_back(in);
    }

    sort(v.begin(), v.end(), comp);
    for(auto i : v) {
        cout << i.age << " " << i.name << "\n";
    }
}