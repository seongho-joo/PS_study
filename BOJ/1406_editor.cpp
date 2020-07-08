#include <iostream>
#include <list>
#include <string>
#define fastIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main() {
    fastIO();
    string word;
    cin >> word;

    list<char> editor(word.begin(), word.end());
    /** word.begin() ~ word.end()를 복사
     * for(int i = 0; i < word.size(); i++) {
     *  editor.push_back(word[i]);
     * }
     * ↑↑ 코드와 비슷
     */
    auto cursor = editor.end(); // 커서 처음위치는 마지막에 위치한다
    int i;
    int T; // testcase
    cin >> T;
    while (T--) {
        char cmd, text;
        cin >> cmd;
        switch (cmd) {
        case 'L': 
        /** 
         * 커서를 왼쪽으로 한 칸 옮김 (커서가 문장의 맨 앞이면 무시됨) 
        */
            if(cursor != editor.begin()) // cursor가 시작위치가 아닐 때
                cursor--;
            break;
        case 'D':
        /**
         * 커서를 오른쪽으로 한 칸 옮김 (커서가 문장의 맨 뒤이면 무시됨)
         */
            if(cursor != editor.end()) // cursor가 마지막 위치가 아닐 때
                cursor++;
            break;
        case 'B': 
        /** 
         * 커서 왼쪽에 있는 문자를 삭제함 (커서가 문장의 맨 앞이면 무시됨 
         * 삭제로 인해 커서는 한 칸 왼쪽으로 이동한 것처럼 나타나지만, 실제로 커서의 오른쪽에 있던 문자는 그대로임
         */
            if(cursor != editor.begin()) {
                cursor--;
                cursor = editor.erase(cursor);
                /**
                 * erase는 삭제하고 다음 위치를 반환
                 */
            }
            break;
        case 'P':
        /**
         * ex) P $
         * $라는 문자를 커서 왼쪽에 추가함
         */
            char ch;
            cin >> ch;
            editor.insert(cursor, ch);
            break;
        }
    }
    for(auto i : editor) cout << i;
    return 0;
}