#include<iostream>
#include<string>
using namespace std;
// �빮�ڿ� �ҹ��� gap = 32
int main() {
	string alpabet;
	int  index, cnt = 0;
	cin >> alpabet;
	int result[26];
	for (int i = 0; i < 26; i++)
		result[i] = 0;

	for (int i = 0; i < alpabet.length(); i++) {
		if (alpabet[i] < 97) alpabet[i] += 32; // �빮���� �� �ҹ��ڷ� �ٲ���
		index = alpabet[i] - 97; // index�� 0~25��  a~z�� ���
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