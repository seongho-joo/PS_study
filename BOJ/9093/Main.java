import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {

    public static Scanner sc = new Scanner(System.in);
    public static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

    public static void main(String[] args) throws IOException {

        int T = 0;
        String input = "";
        T = Integer.parseInt(br.readLine());

        for (int i = 0; i < T; i++) {
            input = br.readLine();
            String[] split = str.split(" ");
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