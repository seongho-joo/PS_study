#include <iostream>
#include <fstream>
#define MAX_NUM 10001
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
    ifstream inp("test.inp");
    ofstream out("test.out");
    int count[MAX_NUM] ={0};
    int N, data, max = 0;
    // cin >> N;
    inp >> N;
    for (int i = 0; i < N; i++) {
        // cin >> data;
        inp >> data;
        count[data]++;
    }

    for (int i = 0; i < N; i++) {
        if(count[i]>0) {
            for (int j = 0; j < count[i]; j++)
                cout << i << "\n";
        }
    }
    inp.close();
    out.close();
    return 0;
}