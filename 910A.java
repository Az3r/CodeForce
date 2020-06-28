
import java.util.Arrays;
import java.util.Scanner;

public final class Scratch {

    private static boolean[][] IsUsed;

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int d = scanner.nextInt();
        String s = scanner.next();

        IsUsed = new boolean[n][d];
        for (boolean[] e : IsUsed) Arrays.fill(e, false);

        System.out.println(solve(s, 0, d));
    }


    public static int solve(String s, int i, int d) {
        for (int a = d; a > 0; --a) {
            if (issafe(s, i + a) && !IsUsed[i][a - 1]) {
                if (i + a == s.length() - 1) return 1;

                int move = solve(s, i + a, d);
                if (move > 0) return 1 + move;
                IsUsed[i][a - 1] = true;
            }
        }
        return -1;
    }

    public static boolean issafe(String s, int i) {
        return i < s.length() && s.charAt(i) == '1';
    }

}