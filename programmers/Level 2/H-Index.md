## 🔗 문제링크
[코딩테스트 연습 > 정렬 > H-Index](https://programmers.co.kr/learn/courses/30/lessons/42747)

## 📝 문제 설명
H-Index는 과학자의 생산성과 영향력을 나타내는 지표입니다. 어느 과학자의 H-Index를 나타내는 값인 h를 구하려고 합니다. 위키백과[<sup>1</sup>](https://en.wikipedia.org/wiki/H-index)에 따르면, H-Index는 다음과 같이 구합니다.

어떤 과학자가 발표한 논문 `n`편 중, `h`번 이상 인용된 논문이 `h`편 이상이고 나머지 논문이 `h`번 이하 인용되었다면 `h`의 최댓값이 이 과학자의 H-Index입니다.

어떤 과학자가 발표한 논문의 인용 횟수를 담은 배열 citations가 매개변수로 주어질 때, 이 과학자의 H-Index를 return 하도록 solution 함수를 작성해주세요.

## ⚠️ 제한사항
- 과학자가 발표한 논문의 수는 1편 이상 1,000편 이하입니다.
- 논문별 인용 횟수는 0회 이상 10,000회 이하입니다.

## 🖨 입출력 예
citations|return
--|--
[3, 0, 6, 1, 5]|3

## 📂 분류
`정렬`

## 💡 풀이
문제를 이해하는 것이 전부였다. 문제를 이해하려고 몇 번을 읽어봤으나 예시가 하나밖에 없어 이해가 안 됐다.   
https://www.ibric.org/myboard/read.php?Board=news&id=270333   
H-Index에 대한 이해는 위 링크를 보고 이해를 했다. 

우선 `citations`을 오름차순으로 정렬을 한다. 오름차순으로 정렬을 했기 때문에 hIndex는 배열의 길이 - i가 된다.   
그리고 배열 순회를 하면서 hIndex가 `citations[i]`이하가 되면 `answer`에 hIndex를 저장하고 for 문을 빠져나간다.

## 💻 코드
```java
import java.util.*;

class Solution {
    public int solution(int[] citations) {
        int answer = 0, len = citations.length;
        Arrays.sort(citations);
        for (int i = 0; i < len; i++) {
            int hIndex = len - i;
            if (citations[i] >= hIndex) {
                answer = hIndex;
                break;
            }
        }
        return answer;
    }
}
```