// 중복x 오름차순 정렬
#include <iostream>
#include <set>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int N; // ¼ýÀÚ °³¼ö
    cin >> N;
    set<int> s;

    while (N--)
    {
        int num;
        cin >> num;
        s.insert(num);
    }

    for (auto i : s)
        cout << i << " ";

    return 0;
}
