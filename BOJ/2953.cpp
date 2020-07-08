/**
 * BOJ2953 - 나는 요리사다
 */
#include <iostream>
#define fastIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

typedef struct Grade{
    int grade[5];
    int total = 0; // 최종 점수
}Grade;

int main () {
    fastIO();
    int N = 5;

    int max = 0, index = 0;
    
    for(int j = 0; j < N; j++) {
        Grade gr;
        for(int i = 0; i < 4; i++) {
            cin >> gr.grade[i];
            gr.total += gr.grade[i];
        }
        if(max < gr.total) {
            max = gr.total;
            index = j + 1;
        };
    }
    
    cout << index << " " << max;

    return 0;
}