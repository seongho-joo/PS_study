#include <iostream>
#include <string>
using namespace std;

int main(){
	int T,R; // 경우의 수, 반복 횟수
	cin >> T;
	string S;
		for (int i = 0; i < T; i++) {
			string P = "";
			cin >> R >> S;
			for (int j = 0; j<S.length(); j++) {
				for (int k = 0; k < R; k++) {
					P += S[j];
				}
			}
			cout << P << endl;
	}
	return 0;
}