/**
 * BOJ1914 하노이탑
 * BigInteger를 활용해서 푼 하노이 탑
 */
import java.math.BigInteger;
import java.util.Scanner;

public class BOJ1914 {
    static void hanoi(int n, int from, int by, int to) {
        if(n == 1) {
            System.out.println(from + " " + to);
            return;
        }
        else {
            hanoi(n - 1, from, to, by);
            System.out.println(from + " " + to);
            hanoi(n - 1, by, from, to);
        }
    }
    public static void main (String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        sc.close();
        BigInteger bInteger = new BigInteger("2");
        BigInteger res = bInteger.pow(n).subtract(BigInteger.ONE);
        System.out.println(res);

        if(n <= 20) hanoi(n, 1, 2, 3);
    }
}