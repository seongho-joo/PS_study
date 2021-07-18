### 🔥 난이도
`Level 1`

### 📝 문제설명

배열 array의 i번째 숫자부터 j번째 숫자까지 자르고 정렬했을 때, k번째에 있는 수를 구하려 합니다.   
예를 들어 array가 [1, 5, 2, 6, 3, 7, 4], i = 2, j = 5, k = 3이라면   
1. array의 2번째부터 5번째까지 자르면 [5, 2, 6, 3]입니다.   
2. 1에서 나온 배열을 정렬하면 [2, 3, 5, 6]입니다.   
3. 2에서 나온 배열의 3번째 숫자는 5입니다.   

배열 array, [i, j, k]를 원소로 가진 2차원 배열 commands가 매개변수로 주어질 때, commands의 모든 원소에 대해 앞서 설명한 연산을 적용했을 때 나온 결과를 배열에 담아 return 하도록 solution 함수를 작성해주세요.   

### ⌛️ 제한 조건
- array의 길이는 1 이상 100 이하입니다.
- array의 각 원소는 1 이상 100 이하입니다.
- commands의 길이는 1 이상 50 이하입니다.
- commands의 각 원소는 길이가 3입니다.

### 🖨 입출력 예
array|commands|return
--|--|--
[1, 5, 2, 6, 3, 7, 4]|	[[2, 5, 3], [4, 4, 1], [1, 7, 3]]	|[5, 6, 3]

### 💻 풀이 코드
```cpp
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int sliceArray(vector<int> arr, int s, int e, int index) {
    vector<int> temp;
    for(int i = s; i <= e; i += 1) {
        temp.push_back(arr[i]);
    }
    sort(temp.begin(), temp.end());
    return temp[index];
}

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    for(int i = 0; i < commands.size(); i++) {
        for(int j = 0; j < commands[i].size(); j++) {
            commands[i][j] -= 1;
        }
    }
    vector<int> answer(commands.size());
    for(int i = 0; i < commands.size(); i++) {
        answer[i] = sliceArray(array, commands[i][0], commands[i][1], commands[i][2]);
    }
    
    return answer;
}
```

### ✍🏻 풀이
- 인덱스로 접근하기 위해 `commands` 이차원 벡터의 값을 -1을 해줌
- `sliceArray`함수에 i번째 숫자는 `s`, j번째 숫자는 `e`, k번째는 `index`를 매개변수로 넘겨줌
- `temp`벡터를 선언해주고 s부터 e까지의 수를 담아주고 정렬을 한 다음 `temp[index]` 값을 리턴
- `sliceArray`함수의 리턴값을 `answer` 벡터의 저장해줌
