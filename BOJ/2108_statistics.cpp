#include <iostream>
#include <fstream>
#include <algorithm>
#include <map>
#include <cmath>
#include <vector>
using namespace std;

vector<int> v;

bool compare(const pair<int, int> &x, const pair<int, int> &y) {
	if (x.second == y.second) return x.first < y.first;
	return x.second > y.second;
}

/* 최빈값을 구함 */
void getMode(int N) {
	vector<pair <int, int> > count; // pair <key, count>
	int cnt = 1;
	/* 주어진 값들의 빈도 수를 셈 */
	for (int i = 0; i < N; i++) {
		if (count.empty()) { 
			count.push_back(make_pair(v[i], 1));
			continue;
		}
		if (count.back().first == v[i]) { // 같은 수가 있을 시
			pair<int, int> temp = count.back();
			temp.second++; // count++
			count.pop_back(); // 중복방지를 위해 pop시켜줌
			count.push_back(temp);
		}
		else count.push_back(make_pair(v[i], 1));
	}
	sort(count.begin(), count.end(), compare); // 빈도 수 내림차순
	if (count[0].second > count[1].second) cout << count[0].first << "\n";
	else cout << count[1].first << "\n";
}

int main() {
	ifstream inp("test.inp");
	cin.tie(NULL);

	int N, num;
	double sum = 0;
	cin >> N;
	//inp >> N;
	v.reserve(N);

	for (int i = 0; i < N; i++) {
		cin >> num;
		//inp >> num;
		sum += num;
		v.push_back(num);
	}
	sort(v.begin(), v.end());

	cout << (int)floor((sum / N) + 0.5) << "\n"; // 평균 값 출력
	cout << v[N / 2] << "\n"; // 중앙 값 출력

	if (N != 1)
		getMode(N);
	else cout << v[0] << "\n";
	cout << v.back() - v.front();
	return 0;
}