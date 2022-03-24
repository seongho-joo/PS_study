[문제 링크](https://www.acmicpc.net/problem/9093)

![image](https://user-images.githubusercontent.com/45463495/159862435-c9304b5f-9825-4f52-b781-b56a149a7f7b.png)
![image](https://user-images.githubusercontent.com/45463495/159862459-3f78e970-8038-46fa-8155-8be6f3888dfa.png)


## 📂 분류
`문자열`, `구현`

## 💡 풀이
주어진 문자열을 ' '로 split하고 `StringBuilder`에 넣어서 `reverse()` 메서드를 사용해서 풀었다.

## 💻 코드
```java
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {

    public static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

    public static void main(String[] args) throws IOException {

        int T = 0;
        String input = "";
        T = Integer.parseInt(br.readLine());

        for (int i = 0; i < T; i++) {
            input = br.readLine();
            String[] split = input.split(" ");
            StringBuilder sb = new StringBuilder();

            for (String s : split) {
                StringBuilder reverse = new StringBuilder(s);
                sb.append(reverse.reverse());
                sb.append(' ');
            }

            sb.deleteCharAt(sb.length() - 1);
            System.out.println(sb);
        }
    }
}
```