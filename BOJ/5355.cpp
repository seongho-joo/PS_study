/**
 * BOJ5355 - 화성 수학
 */
#include <iostream>
#include <string>
#define fastIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

void marsMath(string str, double data) {
    double res = data;
    for (int j = 0; j < str.size(); j++) {
        char ch = str.at(j);

        if (ch == ' ') continue;

        switch (ch){
        case '@':
            res *= 3.0;
            break;
        case '%':
            res += 5.0;
            break;
        case '#':
            res -= 7.0;
            break;
        }
        }
        printf("%.2f\n", res);
}

int main() {
    fastIO();
    int N;
    cin >> N;

    string str;
    double data;
    for(int i = 0; i < N; i++) {
        cin >> data;
        getline(cin, str); // 공백까지 입력을 받는 함수
        marsMath(str, data);
        str.clear();
    }

    return 0;
}