#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	ifstream inp("input.txt");
	ofstream out("output.txt");
	priority_queue<int> Min_heap;
	int T;
	cin >> T;
	while (T--) {
		int integer;
		cin >> integer;
		if (!integer) {
			if (Min_heap.empty()) cout << 0 << "\n";
			else {
				cout << Min_heap.top() << "\n";
				Min_heap.pop();
			}
		}
		else {
			Min_heap.push(integer);
		}
	}

	return 0;
}