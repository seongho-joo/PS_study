#include <iostream>
#include <cstring>
using namespace std;

int main() {
	char a[100];
	cin >> a;
	int size = strlen(a);
	int alpabet[26];
	for (int i = 0; i < 26; i++)
		alpabet[i] = -1;
	int index = 0;
	for (int i = 0; i < size; i++) {
		index = a[i] - 97;
		if (alpabet[index] == -1)
			alpabet[index] = i;
	}
	for (int i = 0; i < 26; i++)
		cout << alpabet[i] << " ";
	cout << endl;
	return 0;
}