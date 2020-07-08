#include <iostream>
#include <vector>
using namespace std;

void Solution (vector<pair<int,int> > &v){
    while(!v.empty()){
        cout << v.front().first << " ";
        int vNum = v.front().second; // 이동할 수
        v.erase(v.begin()); // 첫 번째 요소를 삭제

        /* 변화량이 양수일 때 */
        if (vNum > 0) {
            for (int i = 0; i < vNum - 1; i++) {
                v.push_back(v.front()); // 앞에 있는 요소를 뒤로 보냄
                v.erase(v.begin());
            }
        }
        /* 변화량이 음수 일 때*/
        else {
            for (int i = 0; i < abs(vNum); i++){
                v.insert(v.begin(), v.back()); // 뒤에 있는 요소를 앞으로 보냄
                v.erase(v.end());
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
    
    vector<pair<int, int> > v;
    int N; // 풍선의 개수
    cin >> N;

    for (int i = 1; i <= N; i++)
    {
        int num;
        cin >> num;
        v.push_back(make_pair(i, num));
    }

    Solution(v);

    return 0;
}