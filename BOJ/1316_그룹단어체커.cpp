#include <iostream>
#include <vector>
#include <string>
using namespace std;
bool wordChk(string word) {
	vector<bool> chk(26, false);

	for (int i = 0; i < word.size(); i++) {
		if (chk[word[i] - 'a']) return false;
		else {

			char temp = word[i];
			chk[temp - 'a'] = true;

			while (true) {
				if (temp != word[++i]) { 
					i--;
					break; 
				}
			}
		}
	}
	return true;
}

int main() {
	string word;
	int n, count = 0;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> word;
		if (wordChk(word)) count++;
	}
	cout << count;
	return 0;
}