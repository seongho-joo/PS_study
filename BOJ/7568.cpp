/**
 * BOJ - 7568 덩치
 * 분류 - 브루트포스
 * 이름	<몸무게, 키> 덩치 등수
    A	<55, 185>	    2
    B	<58, 183>	    2
    C	<88, 186>	    1
    D	<60, 175>	    2
    E	<46, 155>	    5
 */
#include <iostream>
#include <vector>
#define fastIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

typedef struct Inform{
    int weight;
    int height;
    int rank;
}Inform;

vector<Inform> v;

void solution() {
    int len = v.size();
    for(auto i = v.begin(); i != v.end(); i++) {
        for(auto j = v.begin(); j != v.end(); j++) {
            if(i->height < j->height && i->weight < j->weight) {
                i->rank++;
            }
        }
    }
}

int main() {
    fastIO();
    int N;
    cin >> N;

    v.reserve(N);

    while(N--) {
        Inform in;
        cin >> in.weight >> in.height;
        in.rank = 1;
        v.push_back(in);
    }
    solution();
    for(auto i : v) {
        cout << i.rank << " ";
    }
}