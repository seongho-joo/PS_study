#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

vector<vector<int> > array;
vector<int> count;

bool paperChk(int N, int row, int col) {
    int s = array[row][col];
    for(int i = row; i < N + row; i++) {
        for(int j = col; j < N + col; j++) {
            if(s != array[i][j]) 
                return false;
        }
    }
    return true;
}

void paperDiv(int N, int row, int col) {
    /* 기저사례1 : N이 1일 때 */
    if(N == 1) {
        count[array[row][col]]++;
        return;
    }
    // 기저사례2 : N개의 원소가 같을 때
    if(paperChk(N, row, col)) {
        count[array[row][col]]++;
        return;
    }
    else {
     for(int i = 0; i < 3; i++) {
         for(int j = 0; j < 3; j++) {
               paperDiv(N / 3, row + (N / 3) * i, col + (N / 3) * j);
          }
      }
    }
}

int main() {
    // ifstream cin("cin.txt");
    // ofstream cout("cout.txt");
    int N;
    cin >> N;
    array.resize(N, vector<int>(N));

    count.resize(3, 0);

    int num;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> num;
            array[i][j] = num + 1;
        }
    }

    paperDiv(N,0, 0);

    for(int i = 0; i < 3; i++) {
        cout << count[i] << "\n";
    }

    return 0;
}