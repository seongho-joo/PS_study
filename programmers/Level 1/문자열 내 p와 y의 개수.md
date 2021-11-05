## 🔥 난이도
`Level1`

## 📝 문제설명
대문자와 소문자가 섞여있는 문자열 s가 주어집니다. s에 'p'의 개수와 'y'의 개수를 비교해 같으면 True, 다르면 False를 return 하는 solution를 완성하세요. 'p', 'y' 모두 하나도 없는 경우는 항상 True를 리턴합니다. 단, 개수를 비교할 때 대문자와 소문자는 구별하지 않습니다.   
예를 들어 s가 "pPoooyY"면 true를 return하고 "Pyy"라면 false를 return합니다.

## ⌛️ 제한 조건
- 문자열 s의 길이 : 50 이하의 자연수
- 문자열 s는 알파벳으로만 이루어져 있습니다.

## 🖨  입출력 예
s |	answer
--|--
"pPoooyY" |	true
"Pyy" |	false

## 💻 풀이 코드
```cpp
#include <string>
#include <iostream>
using namespace std;

bool solution(string s) {
    int p = 0, y = 0;
    for (char c : s) {
        if (c == 'p' || c == 'P') p += 1;
        else if (c == 'y' || c == 'Y') y += 1;
    }
    return  p == y;
}
```

## ✍🏻 풀이 및 분류
- `구현`