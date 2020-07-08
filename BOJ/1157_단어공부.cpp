#include<iostream>
#include<string>
using namespace std;
// 대문자와 소문자 gap = 32
int main() {
	string alpabet;
	int  index, cnt = 0;
	cin >> alpabet;
	int result[26];
	for (int i = 0; i < 26; i++)
		result[i] = 0;

	for (int i = 0; i < alpabet.length(); i++) {
		if (alpabet[i] < 97) alpabet[i] += 32; // 대문자일 때 소문자로 바꿔줌
		index = alpabet[i] - 97; // index는 0~25를  a~z를 대신
		result[index]++;
	}

	int max = 0, index_max;
	for (int i = 0; i < 26; i++) {
		if (max < result[i]) {
			max = result[i];
			index_max = i + 65;
			cnt = 0;
		}
		else if (max > 1 && max == result[i]) 
			cnt = 1;
		
	}
	if (cnt == 1) cout << "?" << endl;
	else cout << (char)index_max << endl;
	return 0;
}