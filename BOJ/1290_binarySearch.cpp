#include <iostream>
#include <algorithm>
#include <vector>
#define MAX 100000
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	int n;
	cin >> n;
	vector<int> arr;
	arr.reserve(n);
	int num;
	for (int i = 0; i < n; i++) {
		cin >> num;
		arr.push_back(num);
	}
	sort(arr.begin(), arr.end());
	cin >> n;
	while (n--) {
		cin >> num;
		if (binary_search(arr.begin(), arr.end(), num)) cout << 1 << "\n";
		else cout << 0 << "\n";
	}

	return 0;
}