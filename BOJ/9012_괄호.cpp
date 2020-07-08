#include <iostream>
#include <fstream>
#include <stack>
#include <string>
using namespace std;

bool checkVPS(string ch) {
	stack<char> st;
	int size = ch.size();
	for (int i = 0; i < size; i++) {
		if (ch[i] == '(') st.push(ch[i]);
		else {
			if (!st.empty()) st.pop();
			else 
				return false;
		}
	}
	if(st.empty()) return true;
	else return false;
}

int main() {
	ifstream inp("input.txt");
	ofstream out("output.txt");
	int n;
	cin >> n;
	while (n--) {
		string ch;
		cin >> ch; 
		if (checkVPS(ch)) cout << "YES" << endl;
		else cout << "NO" << endl;
		ch = "";
	}
	return 0;
}