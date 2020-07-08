#include <iostream>
#include <fstream>
#include <queue>
using namespace std;
queue<int> q;

int solution() {
	int num = q.front();
	while (q.size() > 1) {
		q.pop();
		num = q.front(); q.push(num);
		q.pop();
	}
	return num;
}

int main() {
	
	int N;
	cin >> N;
	for (int i = 1; i <= N; i++)
		q.push(i);
	cout << solution() << endl;

	return 0;
}